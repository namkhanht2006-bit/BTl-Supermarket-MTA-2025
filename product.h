#include<string>
#include<iostream>
#include<vector>
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

    virtual void them();
    virtual void in();
    string getname() { return name; };
    string getid() { return id; };
    double getprice() { return price; };
};
