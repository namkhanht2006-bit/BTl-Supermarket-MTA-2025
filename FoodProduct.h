class FoodProduct:public product {
    string Expiry;
    string Nutrition;
    public:
    void setId(const string &v){id =v; };
    void setName(const std::string& v) { name = v; }
    void setPrice(double v) { price = v; }
    void setQuantity(int v) { quantity = v; }
    void setBrand(const string& v) { brand = v; }
    void setWeight(float v) { weight = v; }
    void setWarranty(const string& v) { warranty = v; }
    void setSeri(const string& v) { seri = v; }
    
    double price_discount(int qty) const;
    string type() const;

};
