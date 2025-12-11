#include<string>
#include<iostream>
#include<vector>
#include <fstream>
#pragma once

using namespace std;
class product {
protected:
    string name;
    string id;
    double price;
    string brand;
    float weight;
    int quantity;
    public:
    virtual double price_discount(int qty) const = 0;
    virtual string type() const = 0;
    virtual void them(istream& in);
    virtual void in(ostream &out);
    string getname() { return name; };
    string getid() { return id; };
    double getprice() { return price; };
    friend ostream& operator<<(ostream& out, product& p);
    friend istream& operator>>(istream& in, product& p);
};



