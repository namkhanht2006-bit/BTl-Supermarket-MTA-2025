#include<string>
#include<iostream>
#include<vector>
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
    virtual bool Can_sell(int qty) ;
    virtual double price_discount(int qty) const = 0;
    virtual string type() const = 0;

    virtual void them(istream &is);
    virtual void in(ostream &os);
    string getname() { return name; };
    string getid() { return id; };
    double getprice() { return price; };
    friend istream &operator>>(istream &is, product &p);
    friend ostream &operator<<(ostream &os, const product &p);

};
