#include"product.h"
using namespace std;
void product::them(istream &in) {
    cout<<"Nhap ma san pham";getline(in,id);
    cout<<"Nhap ten san pham";getline(in,name);
    cout<<"Nhap gia san pham";in>>price;in.ignore();
    cout<<"Nhap thuong hieu san pham";getline(in,brand);
    cout<<"Nhap so luong san pham";getline(in,quantity);
    cout<<"Nhap khoi luong san pham";getline(in,weight);
}
void product::in() {
    cout<<"Ma so: "<<id<<endl;
    cout<<"Ten: "<<name<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Thuong hieu: "<<brand<<endl;
    cout<<"So luong san pham: "<<quantity<<endl;
    cout<<"Can nang: "<<weight<<endl;
}
ostream& operator<<(ostream& out, const product& p) {
    p.print(out);
    return out;
}

istream& operator>>(istream& in, product& p) {
    p.input(in);
    return in;
}

