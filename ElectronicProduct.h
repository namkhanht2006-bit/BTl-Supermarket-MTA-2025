#include"product.h"
#include<vector>
class ElectronicProduct:product{
    protected:
    string warranty;
    string seri;
public:
    string getWarranty() const { return warranty; }
    string getSeri() const { return seri; }
    double price_discount(int qty) const;
    string type() const;
    void them(istream &is) override;
    void in(ostream &os) override;
    friend istream& operator>>(istream& is, ElectronicProduct& e);
    friend ostream& operator<<(ostream& os, ElectronicProduct& e);
    bool Can_sell(int qty);
};
