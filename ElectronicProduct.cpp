
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
void ElectronicProduct::them(istream &is) {
    product::them(is);
    cout<<"Nhap bao hanh: "<<endl;
    is>>warranty;
    cout<<"Nhap so seri: "<<endl;
    is>>seri;

}
void ElectronicProduct::in(ostream &os) {
    product::in(os);
    os<<"Thoi han bao hanh: "<<warranty<< endl;
    os<<"So seri: "<<seri<<endl;
}

istream& operator>>(istream& is, ElectronicProduct& e) {
    e.them(is);
}

ostream& operator<<(ostream& os, ElectronicProduct& e) {
    e.in(os);

}


