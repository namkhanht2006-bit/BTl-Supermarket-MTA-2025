#include "Order.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>

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

double Order::Total() const {
    double t = 0.0;
    for (const auto &it : danhSachMuc) t += it.buy;
    return t;
}

std::string Order::toTextHoaDon() const {
    std::ostringstream oss;
    oss << "Hoa don: " << order_id << "\n";
    oss << "Khach hang: " << customer_id << "\n";
    oss << "Ngay: " << date << "\n";
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
    if (kh.getCart().danhSach.empty()) return false;
    Order od(maDonMoi, kh.getCustomerId(), getTime());
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
        // reduce stock in supermarket
        sm.giamSoLuong(item.maSP, item.Soluong);
    }
    out = std::move(od);
    return true;
}
Order::Order()
    : order_id(""), customer_id(""), date(""), danhSachMuc()
{}
