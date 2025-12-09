
#include "ElectronicProduct.h"
#include"product.h"
string ElectronicProduct::type() const {
    return "Electronic";
}

double ElectronicProduct::price_discount(int qty) const {
    if (qty >= 50) return price * qty * 0.9;
    if (qty >= 10) return price * qty * 0.95;
    return price * qty;
}


