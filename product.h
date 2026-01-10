#pragma once
#include<string>
#include<iostream>
#include <fstream>


using namespace std;
class product {
protected:
    string name;
    string id;
    double price;
    string brand;
    double weight;
    int quantity;
public:
    virtual double price_discount(int qty) const = 0;
    virtual string type() const = 0;
    virtual void them(istream& in);
    virtual void them_file(istream& is);
    virtual void in(ostream& out) const;
    friend ostream& operator<<(ostream& out, const product& p);
    friend istream& operator>>(istream& in, product& p);
    virtual bool Can_sell(int qty) const;

    void setid(string& v) { id = v; }
    void setname(string& v) { name = v; }
    void setprice(double v) { price = v; }
    void setbrand( string& v) { brand = v; }
    void setquantity(int v) { quantity = v; }
    void setweight(double v) { weight = v; }
    string getid() const { return id; }
    string getname() const { return name; }
    double getprice() const { return price; }
    int getquantity() const { return quantity; }
    double getweight() const { return weight; }
    string getbrand()const { return brand; }
    product();
    product(string name, string id, double price, string brand, double weight, int quantity);
    ~product();
};