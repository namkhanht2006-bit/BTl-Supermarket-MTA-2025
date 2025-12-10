#include"product.h"
#include<vector>
class ElectronicProduct:product{
    string material;
    string usage;
public:
    void them(istream& in) ;
    void in(ostream& out) const ;
    string getMaterial() const { return material; }
    string getUsage() const { return usage; }
    double price_discount(int qty) const;
    string type() const;
    Householdproduct();
    Householdproduct(string Usage,string Material);
    ~Householdproduct();
    friend ostream& operator<<(ostream& out, const Householdproduct& p);
    friend istream& operator>>(istream& in, Householdproduct& p);
};

