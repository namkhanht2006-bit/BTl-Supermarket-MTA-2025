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
    virtual void them_file(istream& is);
    virtual void in(ostream &out) const;
    string getname() { return name; };
    string getid() { return id; };
    double getprice() { return price; };
    friend ostream& operator<<(ostream& out, const product& p);
    friend istream& operator>>(istream& in, product& p);
    virtual bool Can_sell(int qty) const;

    void setid(const std::string& v) { id = v; }
    void setname(const std::string& v) { name = v; }
    void setprice(double v) { price = v; }
    void setbrand(const std::string& v) { brand = v; }
    void setquantity(int v) { quantity = v; }
    void setweight(double v) { weight = v; }

    std::string getid() const { return id; }
    std::string getname() const { return name; }
    double getprice() const { return price; }
    int getquantity() const { return quantity; }
    double getweight() const { return weight; }


};



