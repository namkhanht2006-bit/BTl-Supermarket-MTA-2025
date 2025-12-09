class FoodProduct:public product {
    string expiry;
    string nutrition;
    public:
    void readfile(istream &is);
    void writefile(ostream &os);
    void inputfile(istream &is);
    double price_discount(int qty) const;
    string type() const;

};
