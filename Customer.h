#include "cart.h"
using namespace std;
class Customer
{private :
	Cart cart;
	string Name;
	string Gender;
	string PhoneNumber;
	string Address;
	double Age;
public:
	
	Customer();
	Customer(string name, string gender, string phonenumber, string address, double age);
	~Customer();
	void input();
	void output();
	Cart& getCart() { return cart; }
	const Cart& getCart() const { return cart;} 
};
