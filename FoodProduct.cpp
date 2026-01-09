#include <iostream>
#include "FoodProduct.h"
using namespace std;

FoodProduct::FoodProduct(string expiry_, string nutrition_) {
    expiry = expiry_; nutrition = nutrition_;
}
FoodProduct::FoodProduct() {}
FoodProduct::~FoodProduct() {}

string FoodProduct::type() const {
    return "Food";
}

double FoodProduct::price_discount(int qty) const {
    if (price*qty>=300000) return price * qty * 0.8;
    if (price*qty< 300 && price*qty >100000) return price * qty * 0.9;
    return price * qty;
}

void FoodProduct::them(istream& in) {
    product::them(in);
    in.ignore();
    cout << "Nhap han su dung: "; getline(in, expiry);
    cout << "Nhap gia tri dinh duong: "; getline(in, nutrition);
}

void FoodProduct::in(ostream& out) const {
    product::in(out);
    out << "Han su dung: " << expiry << endl;
    out << "Dinh duong: " << nutrition << endl;
}

ostream& operator<<(ostream& out, const FoodProduct& p) {
    p.in(out);
    return out;
}
istream& operator>>(istream& in, FoodProduct& p) {
    p.them_file(in);
    return in;
}

bool FoodProduct::Can_sell(int qty) const { return product::Can_sell(qty); }
void FoodProduct::them_file(istream& in) {
    product::them_file(in);
    in >> expiry >> nutrition;;
}
