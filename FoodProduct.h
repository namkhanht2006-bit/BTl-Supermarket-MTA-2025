class FoodProduct:public product {
    string expiry;
    string nutrition;
    public:
    void them(istream& in);
    void in(ostream &out);
    string getExpiry(string &v)const {return expiry;}
    string getNutrition(string &v) const{return Nutrition;}
    double price_discount(int qty) const;
    string type() const;
    friend ostream& operator<<(ostream& out, const product& p);
    friend istream& operator>>(istream& in, product& p);
    Foodproduct();
    Foodproduct(string expiry,string nutrition);
    ~Foodproduct();
};
