#include"product.h"
#include<vector>
class HouseholdProduct : public product {
private:
    string material;
    string usage;
public:
    void them(istream& in) ;
    void in(ostream& out) const ;
    string getMaterial() const { return material; }
    string getUsage() const { return usage; }
    double price_discount(int qty) const;
    string type() const;
    bool Can_sell(int qty) const;
    HouseholdProduct();
    HouseholdProduct(string Usage,string Material);
    ~HouseholdProduct();
    friend  ostream& operator<<(ostream& out, const HouseholdProduct& p);
    friend  istream& operator>>(istream& in, HouseholdProduct& p);

    void setMaterial(std::string mtr) { material = mtr; }
    void setUsage(string usg) { usage = usg; }

    void them_file(istream &is);
};

