#pragma once
#include <iostream>
#include <string>
#include "cart.h"
using namespace std;
class Customer
{private :
	string Name;
	string Gender;
	string PhoneNumber;
	string Address;
	double Age;
public:
	Cart cart;
	Customer();
	Customer(string name, string gender, string phonenumber, string address, double age);
	~Customer();
	void input();
	void output();
	void Addcart(product* p);
	void Deletecart(const string &id);
	//void Printcart();
	//void Bill(const string& filename);
};
