#pragma once
#include "Cart.h"
#include <string>
class Customer {
private:
    Cart cart;
    std::string Id;
    std::string Name;
    std::string Gender;
    std::string PhoneNumber;
    std::string Address;
    double Age;
public:
    Customer();
    Customer(const std::string& name, const std::string& gender, const std::string& phonenumber, const std::string& address, double age);
    ~Customer();
    void input();
    void output();
    Cart& getCart() { return cart; }
    const Cart& getCart() const { return cart; }
    std::string getCustomerId() const { return Id; }
    std::string getName() const { return Name; }
};
