include <iostream>
#include "HouseholdProduct.h"
using namespace std;
Householdproduct::Householdproduct(string Usage, string Material) {
	usage = Usage; material = Material;
}
Householdproduct::Householdproduct(){}
Householdproduct::~Householdproduct(){}

ostream& operator<<(ostream& out, const Householdproduct& p) {
    p.print(out);
    return out;
}
istream& operator>>(istream& in, Householdproduct& p) {
    p.input(in);
    return in;
}
string HouseholdProduct::type() const {
    return "Household";
}

double HouseholdProduct::price_discount(int qty) const {
    FoodProduct p;
    if (p.price>=500) return price * qty*0.85;
    if (p.price>=200&&p.price <500) return price * qty * 0.90;
    return price * qty;
}
void Householdproduct::them(istream& in) {
    product::them(in);
    cout << "Enter Usage: "; getline(in, usage);
    cout << "Enter Material: "; getline(in,material;
}
void Householdproduct::in(ostream& out) const {
    product::in(out);
    out << "Usage: " << usage << endl;
    out << "Material: " << material<< endl;
}
