#include<string>
#include<iostream>
#include<vector>
#include<memory>
#include<optional>
using namespace std;
class product {
protected:
    string name;
    string id;
    double price;
    string brand;
    float weight;
    public:
    virtual void readfile(istream &is)=0;
    virtual void writefile(ostream &os)=0;
    virtual void inputfile(istream &is)=0;
    virtual double price_discount(int qty) const = 0;
    virtual string type() const = 0;
    string getname() { return name; };
    string getid() { return id; };
    double getprice() { return price; };
};
class FoodProduct:product {
    string expiry;
    string nutrition;
    public:
    void readfile(istream &is);
    void writefile(ostream &os);
    void inputfile(istream &is);
    double price_discount(int qty) const;
    string type() const;

};
class ElectronicProduct:product {
    string warranty;
    string seri;


    public:
    void readfile(istream &is);
    void writefile(ostream &os);
    void inputfile(istream &is);
    double price_discount(int qty) const;
    string type() const;
};
class HouseholdProduct:product {
    string material;
    string usage;
    public:
    void readfile(istream &is);
    void writefile(ostream &os);
    void inputfile(istream &is);
    double price_discount(int qty) const;
    string type() const;

};
class Supermarket {
public:

    std::vector<std::unique_ptr<product>> danhSachSanPham;

    Supermarket() = default;
    ~Supermarket() = default;


    bool taiTuFile(const std::string& tenFile);
    bool luuVaoFile(const std::string& tenFile) const;


    bool them_sp(std::unique_ptr<product> sp);
    bool xao_sp(const std::string& maSanPham);


    product* timTheoMa(const std::string& maSanPham) const;


    bool capNhatSoLuong(const std::string& maSanPham, int slMoi);
    bool tangSoLuong(const std::string& maSanPham, int sl);
    bool giamSoLuong(const std::string& maSanPham, int sl);


    std::vector<product*> layTatCa() const;

};


class Cart {
public:

    struct MucGio {
        std::string maSP;
        product* SPptr;
        int Soluong;
        double price;

        MucGio() : SPptr(nullptr), Soluong(0), price(0.0) {}
        MucGio(product* sp, int sl)
            : SPptr(sp), Soluong(sl), price(sp ? sp->getprice() : 0.0) {
            if (sp) maSanPham = sp->getid();
        }

    };
    std::vector<MucGio> danhSach;
    bool them(product*p, int so_luong);
    bool xoa(const string& id);

    bool thay_sl(const string&id, int so_luong_moi);
    double tong_tien();


};
class Customer {
public:
    std::string customer_id;
    std::string name;
    Cart gioHang;

    Customer() = default;
    Customer(std::string ma, std::string ten)
        : customer_id(std::move(ma)), ten(std::move(ten)) {}

    void deletecart() { gioHang.danhSach.clear(); }


    bool ThemSP(Supermarket& sieuThi, const std::string& maSanPham, int soLuong);
    bool XoaSp(const std::string& maSanPham);
    bool ThaySl(const std::string& maSanPham, int soLuongMoi);

};
class OrderItem {
public:
    std::string product_id;
    std::string name;
    int amount;
    double ori_price;
    double d_price;
    double buy;

    OrderItem() : amount(0), ori_price(0), d_price(0), buy(0) {}
};
class Order {
public:
    std::string order_id;
    std::string customer_id;
    std::string date;
    std::vector<OrderItem> danhSachMuc;

    Order() = default;
    Order(std::string maDon_, std::string maKhach_, std::string ngayGio_)
        : order_id(maDon_), customer_id(maKhach_), date(ngayGio_) {}

    double Total() const;
    std::string toTextHoaDon() const;
    bool ghiRaFile(const std::string& tenFile) const;

    static std::optional<Order>
    taoTuCartVaCheckout(const Customer& khach,
                        Supermarket& sieuThi,
                        const std::string& maDonMoi);
};

