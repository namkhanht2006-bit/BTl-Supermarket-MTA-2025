#include"product.h"
#include<vector>
class ElectronicProduct:product{
    string warranty;
    string seri;
    vector<product> epro;
public:
    void setId(const string &v){id =v; };
    void setName(const std::string& v) { name = v; }
    void setPrice(double v) { price = v; }
    void setQuantity(int v) { quantity = v; }
    void setBrand(const std::string& v) { brand = v; }
    void setWeight(float v) { weight = v; }

    void setWarranty(const std::string& v) { warranty = v; }
    void setSeri(const std::string& v) { seri = v; }

    std::string getWarranty() const { return warranty; }
    std::string getSeri() const { return seri; }
    double price_discount(int qty) const;
    string type() const;

};
