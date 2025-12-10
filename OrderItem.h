#include<string>
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