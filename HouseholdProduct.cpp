#include <iostream>
#include "HouseholdProduct.h"
using namespace std;

double HouseholdProduct::price_discount(int qty) const {
    if (price >= 500) return price * qty * 0.85;
    if (price >= 200 && price < 500) return price * qty * 0.90;
    return price * qty;
}

HouseholdProduct::HouseholdProduct(string Usage, string Material) {
    usage = Usage; material = Material;
}
HouseholdProduct::HouseholdProduct(){}
HouseholdProduct::~HouseholdProduct(){}

ostream& operator<<(ostream& out, const HouseholdProduct& p) {
    p.in(out);
    return out;
}
istream& operator>>(istream& in, HouseholdProduct& p) {
    p.them_file(in);
    return in;
}

string HouseholdProduct::type() const {
    return "Household";
}

void HouseholdProduct::them(istream& in) {
    product::them(in);
    in.ignore();
    cout << "Enter Usage: "; getline(in, usage);
    cout << "Enter Material: "; getline(in, material);
}
void HouseholdProduct::in(ostream& out) const {
    product::in(out);
    out << "Usage: " << usage << endl;
    out << "Material: " << material<< endl;
}

bool HouseholdProduct::Can_sell(int qty) const { return product::Can_sell(qty); }
void HouseholdProduct::them_file(istream& in) {
    product::them_file(in);
    in>>material>>usage;
}