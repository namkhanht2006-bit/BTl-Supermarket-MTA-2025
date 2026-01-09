#pragma once
#include "Cart.h"
#include <string>
class Customer {
private:
    Cart cart;
    std::string Id;
    std::string Name;

    double Age;
public:
    Customer();
    Customer(const std::string& name,const std::string& id);
    ~Customer();
    void input();
    void output();
    Cart& getCart() { return cart; }
    const Cart& getCart() const { return cart; }
    std::string getCustomerId() const { return Id; }
    std::string getName() const { return Name; }
};
