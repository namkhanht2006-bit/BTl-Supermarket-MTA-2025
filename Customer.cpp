#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name,const std::string& gender,const std::string& phonenumber,const std::string& address,double age)
{
    Name = name;Gender = gender;PhoneNumber = phonenumber;Address = address;Age = age;
}

Customer::Customer() {
    Name = "Thinh dz";
    Gender = "Nam";
    PhoneNumber = "0378593671";
    Address = "Ha Noi";
    Age = 19;
}
Customer::~Customer() {}
void Customer::input() {
    std::cout << "nhap ten khach hang:"; std::getline(std::cin, Name);
    std::cout << "nhap tuoi khach hang:"; std::cin >> Age; std::cin.ignore();
    std::cout << "nhap gioi tinh khach hang:"; std::getline(std::cin, Gender);
    std::cout << "nhap sdt khach hang:"; std::cin >> PhoneNumber; std::cin.ignore();
    std::cout << "nhap dia chi khach hang:"; std::getline(std::cin, Address);
}

void Customer::output() {
    std::cout << "Ho va ten : " << Name << "\n";
    std::cout << "Tuoi: " << Age << "\n";
    std::cout << "Gioi tinh: " << Gender << "\n";
    std::cout << "Sdt: " << PhoneNumber << "\n";
    std::cout << "Dia chi: " << Address << "\n";
}
