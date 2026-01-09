#pragma once
#include "product.h"
#include <string>
#include <iostream>
class FoodProduct : public product {
    std::string expiry;
    std::string nutrition;
public:
    void them(std::istream& in);
    void in(std::ostream& out) const;
    double price_discount(int qty) const;
    std::string type() const;
    bool Can_sell(int qty) const;
    void them_file(istream& in); 
    friend std::ostream& operator<<(std::ostream& out, const FoodProduct& p);
    friend std::istream& operator>>(std::istream& in, FoodProduct& p);
    
    FoodProduct();
    FoodProduct(std::string expiry, std::string nutrition);
    ~FoodProduct();
  

    void setExpiry(std::string exp) { expiry = exp; }
    void setNutrition(std::string exp) { nutrition = exp; }
    string getexpiry() { return expiry; };
    string getNutrition() { return nutrition; };

    
};
