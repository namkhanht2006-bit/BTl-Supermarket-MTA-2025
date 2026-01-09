#include "Order.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>

std::string Order::nhapDate() {
    cout << "nhap ngay in hoa don:";
    cin >> date;
    return date;
}
std::string Order::nhapTimein() {
    cout << "nhap thoi gian in hoa don:";
    cin >> timein;
    return timein;
}

double Order::Total() const {
    double t = 0.0;
    for (const auto &it : danhSachMuc) t += it.buy;
    return t;
}

std::string Order::toTextHoaDon() const {
    std::ostringstream oss;
    oss << "Hoa don: " << order_id << "\n";
    oss << "Ten khach hang: " << c_name << "\n";
    oss << "Ma khach hang: "<< c_id<<"\n";
    oss << "Ngay: " << date << "\n";
    oss << "Thoi gian: "<< timein << "\n";
    oss << "San pham:\n";
    for (const auto &it : danhSachMuc) {
        oss << it.product_id << " " << it.name << " SL=" << it.amount << " Price=" << it.buy << "\n";
    }
    oss << "Tong tien: " << Total() << "\n";
    return oss.str();
}

bool Order::ghiRaFile(const std::string& tenFile) const {
    std::ofstream out(tenFile);
    if (!out.is_open()) return false;
    out << toTextHoaDon();
    out.close();
    return true;
}

bool Order::Checkout(const Customer &kh, Supermarket &sm, const std::string &maDonMoi, Order& out) {
    Order::nhapDate();
    Order::nhapTimein();
    if (kh.getCart().danhSach.empty()) return false;
    Order od(maDonMoi,kh.getName(),kh.getCustomerId(), date, timein);
    for (const Cart::MucGio& item : kh.getCart().danhSach) {
        product* p = sm.timTheoMa(item.maSP);
        if (!p) return false;
        if (!p->Can_sell(item.Soluong)) return false;
        OrderItem oi;
        oi.product_id = item.maSP;
        oi.name = p->getname();
        oi.amount = item.Soluong;
        oi.ori_price = p->getprice();
        oi.d_price = p->price_discount(item.Soluong);
        oi.buy = oi.d_price;
        od.danhSachMuc.push_back(oi);

        sm.giamSoLuong(item.maSP, item.Soluong);
    }
    out = std::move(od);
    return true;
}
Order::Order()
    : order_id(""), c_name(""), c_id(""), date(""), danhSachMuc()
{}