#include "Customer.h"
Customer::Customer(string name, string gender,string phonenumber, string address, double age) {
	Name = name; Gender = gender; PhoneNumber = phonenumber; Address = address; Age = age;
}
Customer::Customer() {
	Name = "Thinh dz"; Gender = ' '; PhoneNumber = "0378593671"; Address = "Ha Noi"; Age = 19;
}
Customer::~Customer(){}
void Customer::input() {
	cout << "nhap ten khach hang:"; getline(cin, Name);
	cout << "nhap tuoi khach hang:"; cin >> Age; cin.ignore();
	cout << "nhap gioi tinh khach hang:"; getline(cin,Gender);
	cout << "nhap sdt khach hang:"; cin >> PhoneNumber; cin.ignore();
	cout << "nhap dia chi khach hang:"; getline(cin, Address);
}
void Customer::output() {
	cout << "Ho va ten : " << Name;
	cout << "Tuoi:" << Age;
	cout << "Gioi tinh:" << Gender;
	cout << "Sdt:" << PhoneNumber;
	cout << "Dia chi" << Address;
}
void Customer::Addcart(product* p) {
	cart.AddProduct(p);//phuong thuc them san pham cua class cart
}
void Customer::Deletecart(const string& id) {
	cart.RemoveByID(id);//phuong thuc xoa san pham cua class cart
}
