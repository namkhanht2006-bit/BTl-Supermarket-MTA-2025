#include <iostream>
#include "HouseholdProduct.h"
using namespace std;

double HouseholdProduct::price_discount(int qty) const {
    if (price*qty >= 1500000) return price * qty * 0.75;
    if (price >= 800000 && price < 1500000) return price * qty * 0.85;
    return price * qty;
}



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
    cout << "Nhap cong dung: "; getline(in, usage);
    cout << "Nhap thanh phan cau tao: "; getline(in, material);
}
void HouseholdProduct::in(ostream& out) const {
    product::in(out);
    out << "Cong dung: " << usage << endl;
    out << "Thanh phan cao tao: " << material << endl;
}

bool HouseholdProduct::Can_sell(int qty) const { return product::Can_sell(qty); }
void HouseholdProduct::them_file(istream& in) {
    product::them_file(in);
    in >> material >> usage;
}

HouseholdProduct::HouseholdProduct(string usage, string material) {
    this->usage = usage; this-> material = material;
}

HouseholdProduct::HouseholdProduct() {
    usage = "khong"; material = "go";
}

HouseholdProduct::~HouseholdProduct() {}
