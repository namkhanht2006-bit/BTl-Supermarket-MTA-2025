#include "product.h"
using namespace std;

void product::them(istream &in) {
    cout << "Nhap ma san pham: "; getline(in, id);
    cout << "Nhap ten san pham: "; getline(in, name);
    cout << "Nhap gia san pham: "; in >> price; in.ignore();
    cout << "Nhap thuong hieu san pham: "; getline(in, brand);
    cout << "Nhap so luong san pham: "; in >> quantity;
    cout << "Nhap khoi luong san pham: "; in >> weight;
}

void product::in(ostream &os) const {
    os << "Ma so: " << id << std::endl;
    os << "Ten: " << name << std::endl;
    os << "Price: " << price << std::endl;
    os << "Thuong hieu: " << brand << std::endl;
    os << "So luong san pham: " << quantity << std::endl;
    os << "Can nang: " << weight << std::endl;
}

istream &operator>>(istream &is, product &p) {
    p.them_file(is);
    return is;
}

ostream &operator<<(ostream &os, const product &p) {
    p.in(os);
    return os;
}

bool product::Can_sell(int qty) const {
    return qty > 0 && quantity >= qty;
}
void product::them_file(istream &in) {
    in>>id>>name>>price>>brand>>quantity>>weight;
}
