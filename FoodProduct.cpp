#include <iostream>
#include "FoodProduct.h"
using namespace std;

FoodProduct::FoodProduct(string expiry_, string nutrition_) {
    expiry = expiry_; nutrition = nutrition_;
}
FoodProduct::FoodProduct(){}
FoodProduct::~FoodProduct(){}

string FoodProduct::type() const {
    return "Food";
}

double FoodProduct::price_discount(int qty) const {
    if (price >= 500) return price * qty * 0.9;
    if (price >= 300 && price < 500) return price * qty * 0.94;
    return price * qty;
}

void FoodProduct::them(istream& in) {
    product::them(in);
    // read expiry and nutrition
    in.ignore();
    cout << "Enter expiry: "; getline(in, expiry);
    cout << "Enter nutrition: "; getline(in, nutrition);
}

void FoodProduct::in(ostream& out) const {
    product::in(out);
    out << "Expiry: " << expiry << endl;
    out << "Nutrition: " << nutrition << endl;
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
    in>>expiry>>nutrition;;
}
