
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
void ElectronicProduct::them() {
    product::them();
    cout<<"Nhap bao hanh: "<<endl;
    cin>>warranty;
    cout<<"Nhap so seri: "<<endl;
    cin>>seri;

}
void ElectronicProduct::in() {
    product::in();
    cout<<"Thoi han bao hanh: "<<warranty<< endl;
    cout<<"So seri: "<<seri<<endl;
}

istream& operator>>(istream& is, ElectronicProduct& e) {
    e.them();
}

ostream& operator<<(ostream& os, ElectronicProduct& e) {
    e.in();

}

