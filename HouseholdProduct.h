#include"product.h"
#include<vector>
class ElectronicProduct:product{
    string material;
    string usage;
public:
    void setId(const string &v){id =v; };
    void setName(const std::string& v) { name = v; }
    void setPrice(double v) { price = v; }
    void setQuantity(int v) { quantity = v; }
    void setBrand(const std::string& v) { brand = v; }
    void setWeight(float v) { weight = v; }
    void setMaterial(const std::string& v) { Material= v; }
    void setUsage(const std::string& v) { Usage= v; }
    string getMaterial() const { return material; }
    string getUsage() const { return usage; }
    double price_discount(int qty) const;
    string type() const;
};

