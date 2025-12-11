
#include"OrderItem.h"
#include"Customer.h"
#include<vector>
class Order {
public:
    std::string order_id;
    std::string customer_id;
    std::string date;
    std::vector<OrderItem> danhSachMuc;

    Order();
    Order(std::string maDon_, std::string maKhach_, std::string ngayGio_)
        : order_id(maDon_), customer_id(maKhach_), date(ngayGio_) {}

    double Total() const;
    std::string getTime();
    std::string toTextHoaDon() const;
    bool ghiRaFile(const std::string& tenFile) const;

    bool Checkout(const Customer& kh,
                        Supermarket& sm,
                        const std::string& maDonMoi,
                        Order& out);
    

};


