class FoodProduct:public product {
    string expiry;
    string nutrition;
    public:
    void setId(const string &v){id =v; };
    void setName(const std::string& v) { name = v; }
    void setPrice(double v) { price = v; }
    void setQuantity(int v) { quantity = v; }
    void setBrand(const string& v) { brand = v; }
    void setWeight(float v) { weight = v; }
    void setExpiry(const string& v) { Expiry = v; }
    void setNutrition(const string& v) { Nutrition = v; }
    string getExpiry(string &v)const {return expiry;}
    string getNutrition(string &v) const{return Nutrition;}
    double price_discount(int qty) const;
    string type() const;

};
