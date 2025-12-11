#include"product.h"
using namespace std;
void product::them(istream &in) {
    cout<<"Nhap ma san pham";getline(in,id);
    cout<<"Nhap ten san pham";getline(in,name);
    cout<<"Nhap gia san pham";in>>price;in.ignore();
    cout<<"Nhap thuong hieu san pham";getline(in,brand);
    cout<<"Nhap so luong san pham";in>>quantity;
    cout<<"Nhap khoi luong san pham";in>>weight;
}

void product::in(ostream &os) {
    cout<<"Ma so: ",os<<id;
    cout<<"Ten: ",os<<name<<endl;
    cout<<"Price: ", os<<price<<endl;
    cout<<"Thuong hieu: ",os<<brand<<endl;
    cout<<"So luong san pham: ",os<<quantity<<endl;
    cout<<"Can nang: ",os<<weight<<endl;
}
istream &operator>>(istream &is, product &p) {
    p.them(is);
}

ostream &operator<<(ostream &os, product &p) {
    p.in(os);
}
bool Can_sell(int qty)  {
        return qty > 0 && quantity >= qty;
    }


