include <iostream>
#include "FoodProduct.h"
using namespace std;
Foodproduct::Foodproduct(string expiry,  string nutrition) :product::product(){
	Expiry = expiry; Nutrition = nutrition;
}
Foodproduct::Foodproduct(){}
Foodproduct::~Foodproduct(){}
string FoodProduct::type() const {
    return "Food";
}

double FoodProduct::price_discount(int qty) const {
    FoodProduct p;
    if (p.price>=500) return price * qty*0.9;
    if (p.price>=300&&p.price <500) return price * qty * 0.94;
    return price * qty;
}
void Foodproduct::them(istream& in) {
    product::them(in);
    cout << "Enter Expiry: "; getline(in, Expiry);
    cout << "Enter Allergy: "; getline(in, Allergy);
    cout << "Enter Nutrition: "; getline(in, Nutrition);
    cout << "Enter Storage: "; getline(in, Storage);
}


