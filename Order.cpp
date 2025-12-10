#include<ctime>
#include "Order.h"
#include<chrono>
#include<fstream>
std::string Order::getTime() {
    using namespace std::chrono;

    auto now = system_clock::now();
    std::time_t now_c = system_clock::to_time_t(now);

    std::tm local{};
#if defined(_WIN32)
    localtime_s(&local, &now_c);
#else
    localtime_r(&now_c, &local);
#endif

    std::ostringstream oss;
    oss << std::put_time(&local, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
bool Order::taoTuCartVaCheckout(const Customer &kh, Supermarket &sm, const std::string &maDonMoi, Order& out)
{
    if (kh.gioHang.danhSach.empty()) {
        cout<<"Gio hang trong ";
        return false;
    }
    for (const Cart::MucGio& item: kh.gioHang.danhSach) {
        product* p = sm.timTheoMa(item.maSP);
        if (!p || !p->Can_sell(item.Soluong)){
            cout<<"Khong du hang de ban ";
            return false;
        }

    }

    Order od(order_id, kh.customer_id, getTime());
    struct change {
        std::string ma; int qty;
    };
    vector<change> vc;
for (const Cart::MucGio& item : kh.gioHang.danhSach) {
    product* p = sm.timTheoMa(item.maSP);
    OrderItem oi;
    oi.product_id = item.maSP;
    oi.name = (p ? p->getname() : std::string("Khong truy cap duoc"));
    oi.amount = item.Soluong;
    oi.ori_price =(p ? p->getprice() : 0);
    oi.d_price = (p ? p->price_discount(item.Soluong) : 0);
    oi.buy = oi.d_price* oi.amount;
    od.danhSachMuc.push_back(oi);
}
    std::string fileName = "HD_" + order_id + ".txt";
    if (!od.ghiRaFile(fileName)) {
        for (std::vector<change>::reverse_iterator it = vc.rbegin();
             it != vc.rend(); ++it)
        {
            sm.tangSoLuong(it->ma, it->qty);
        }
        return false;
    }
    out =std::move(od);
    return true;
}


std::string Order::toTextHoaDon() const {
    fstream hd;
    hd.open("HD_" + order_id + ".txt", ios::out);
    if (hd.is_open()) {
        hd<<"Hoa don: "<<order_id<<endl;
        hd<<"Khach hang: "<<customer_id<<endl;
        hd<<"Ngay: "<<date<<endl;
        hd<<"San pham :"<<endl;
        for (int i=0; i<sizeof(danhSachMuc); i++) {
            hd<< danhSachMuc[i].product_id <<" "<< danhSachMuc[i].name << "  SL:"<<danhSachMuc[i].amount <<" Gia sau giam:"<<danhSachMuc[i].d_price <<" Thanh tien:"<<Total();
        }


    }
    hd.close();

}
bool Order::ghiRaFile(const std::string& tenFile) const {
    std::ofstream out(tenFile);
    if (!out.is_open()) {
        cout<<"Khong mo duoc file";
        return false;
    }
    out << toTextHoaDon();

    if (!out.good()) {
        return false;
    }
    out.close();
    return true;

}


