#include"product.h"
#include<vector>
class ElectronicProduct : public product {
protected:
    string warranty;

public:
    void them_file(istream& is);
    double price_discount(int qty) const;
    string type() const;
    void them(istream& is);
    void in(ostream& os) const;
    bool Can_sell(int qty) const;
    friend istream& operator>>(istream& is, ElectronicProduct& e);
    friend ostream& operator<<(ostream& os, const ElectronicProduct& e);
    
    ElectronicProduct();
    ElectronicProduct(string warranty);
    ~ElectronicProduct();

    void setWarranty(string wrt) { warranty = wrt; };
    string getWarranty() const { return warranty; }

   
};
