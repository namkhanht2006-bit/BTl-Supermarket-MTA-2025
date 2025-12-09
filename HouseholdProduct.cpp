include <iostream>
#include "HouseholdProduct.h"
using namespace std;
string HouseholdProduct::type() const {
    return "Household";
}

double HouseholdProduct::price_discount(int qty) const {
    FoodProduct p;
    if (p.price>=500) return price * qty*0.85;
    if (p.price>=200&&p.price <500) return price * qty * 0.90;
    return price * qty;
}

