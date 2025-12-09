include <iostream>
#include "FoodProduct.h"
using namespace std;
string FoodProduct::type() const {
    return "Food";
}

double FoodProduct::price_discount(int qty) const {
    FoodProduct p;
    if (p.price>=500) return price * qty*0.9;
    if (p.price>=300&&p.price <500) return price * qty * 0.94;
    return price * qty;
}


