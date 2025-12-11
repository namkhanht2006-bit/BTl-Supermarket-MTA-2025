#pragma once
#include <string>
#include "Supermarket.h"
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
	void Buy(Supermarket &sp);
	void Deletecart();
	void Changecart();
	//void Printcart();
	//void Bill(const string& filename);
};

