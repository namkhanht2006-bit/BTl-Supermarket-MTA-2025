#include "Supermarket.h"

#include"OrderItem.h"
#include"Customer.h"
#include<vector>
class Order {
public:
    std::string order_id;
    std::string c_name;
    std::string c_id;
    std::string date;
    std::string timein;
    std::vector<OrderItem> danhSachMuc;

    Order();
    Order(std::string maDon,std::string tenKh, std::string maKH, std::string ngayGio_,std::string gio)
        : order_id(maDon),c_name(tenKh),c_id(maKH), date(ngayGio_), timein(gio) {};

    double Total() const;
    std::string getTime();
    std::string toTextHoaDon() const;
    bool ghiRaFile(const std::string& tenFile) const;

    bool Checkout(const Customer& kh,
                        Supermarket& sm,
                        const std::string& maDonMoi,
                        Order& out);
    std::string nhapDate();
    std::string nhapTimein();



};


