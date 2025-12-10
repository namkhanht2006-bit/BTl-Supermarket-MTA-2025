#include"product.h"
using namespace std;
void product::them() {
    cout<<"Nhap ma san pham"<<endl;
    cin>>id;
    cout<<"Nhap ten san pham"<<endl;
    cin>>name;
    cout<<"Nhap gia san pham"<<endl;
    cin>>price;
    cout<<"Nhap thuong hieu san pham"<<endl;
    cin>>brand;
    cout<<"Nhap so luong san pham"<<endl;
    cin>>quantity;
    cout<<"Nhap khoi luong san pham"<<endl;
    cin>>weight;
}
void product::in() {
    cout<<"Ma so: "<<id<<endl;
    cout<<"Ten: "<<name<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Thuong hieu: "<<brand<<endl;
    cout<<"So luong san pham: "<<quantity<<endl;
    cout<<"Can nang: "<<weight<<endl;
}
