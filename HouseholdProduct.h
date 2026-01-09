
#include"product.h"
#include<vector>
class HouseholdProduct : public product {
    string material;
    string usage;
public:
    void them(istream& in);
    void in(ostream& out) const;
    void them_file(istream& is);
    double price_discount(int qty) const;
    string type() const;
    bool Can_sell(int qty) const;
    friend  ostream& operator<<(ostream& out, const HouseholdProduct& p);
    friend  istream& operator>>(istream& in, HouseholdProduct& p);
    
    HouseholdProduct();
    HouseholdProduct(string Usage, string Material);
    ~HouseholdProduct();
    
    void setMaterial(std::string mtr) { material = mtr; }
    void setUsage(string usg) { usage = usg; }
    string getMaterial() const { return material; }
    string getUsage() const { return usage; }
};
