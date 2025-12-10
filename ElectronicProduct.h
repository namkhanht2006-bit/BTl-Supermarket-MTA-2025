#include"product.h"
#include<vector>
class ElectronicProduct:product{
    string warranty;
    string seri;
public:
    string getWarranty() const { return warranty; }
    string getSeri() const { return seri; }
    double price_discount(int qty) const;
    string type() const;
    void nhap();
    void in()
};


