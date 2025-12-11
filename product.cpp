#include"product.h"
using namespace std;
void product::them(istream &in) {
    cout << "Nhap ma san pham: ";
    getline(in, id);

    cout << "Nhap ten san pham: ";
    getline(in, name);

    cout << "Nhap gia san pham: ";
    in >> price;

    cout << "Nhap thuong hieu san pham: ";
    in.ignore();  
    getline(in, brand);

    cout << "Nhap so luong san pham: ";
    in >> quantity;

    cout << "Nhap khoi luong san pham: ";
    in >> weight;
}

void product::in(ostream &os) {
    os << "Ma so: " << id << endl;
    os << "Ten: " << name << endl;
    os << "Gia: " << price << endl;
    os << "Thuong hieu: " << brand << endl;
    os << "So luong: " << quantity << endl;
    os << "Khoi luong: " << weight << endl;
}

istream &operator>>(istream &is, product &p) {
    p.them(is);
    return is;
}

ostream &operator<<(ostream &os, product &p) {
    p.in(os);
    return os;
}



