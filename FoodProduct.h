#pragma once
#include "product.h"
#include <string>
#include <iostream>

class FoodProduct : public product {
    std::string expiry;
    std::string nutrition;
public:
    void them(std::istream& in) override;
    void in(std::ostream &out) const override;
    std::string getExpiry() const { return expiry; }
    std::string getNutrition() const { return nutrition; }
    double price_discount(int qty) const override;
    std::string type() const override;
    bool Can_sell(int qty) const override;
    FoodProduct();
    FoodProduct(std::string expiry, std::string nutrition);
    ~FoodProduct();
    friend std::ostream& operator<<(std::ostream& out, const FoodProduct& p);
    friend std::istream& operator>>(std::istream& in, FoodProduct& p);

    void setExpiry(std::string exp) { expiry = exp; }
    void setNutrition(std::string exp) { nutrition = exp; }

    string getexpiry() { return expiry; };
    string getNutrition() { return nutrition; };

    void them_file(istream& in) ;
};
