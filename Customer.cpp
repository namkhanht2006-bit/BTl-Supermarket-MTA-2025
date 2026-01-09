#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name,const std::string& ma)
{
    Name = name;Id = ma;
}

Customer::Customer() {
    Name = "Thinh dz";
    Id = "T001";

    Age = 19;
}
Customer::~Customer() {}
void Customer::input() {
    std::cout << "nhap ten khach hang:"; std::getline(std::cin>>ws, Name);
    std::cout << "nhap ma khach hang:"; std::getline(std::cin>>ws,Id );

}

void Customer::output() {
    std::cout << "Ho va ten : " << Name << "\n";
    std::cout << "Ma: " << Id << "\n";

}
