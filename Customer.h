#include"product.h"
#include"Cart.h"
#include"Supermarket.h"
class Customer {
public:
    std::string customer_id;
    std::string name;
    Cart gioHang;

    Customer() = default;
    Customer(std::string ma, std::string ten)
        : customer_id(std::move(ma)), name(std::move(ten)) {}

    void deletecart() { gioHang.danhSach.clear(); }


    bool ThemSP(Supermarket& sieuThi, const std::string& maSanPham, int soLuong);
    bool XoaSp(const std::string& maSanPham);
    bool ThaySl(const std::string& maSanPham, int soLuongMoi);

};