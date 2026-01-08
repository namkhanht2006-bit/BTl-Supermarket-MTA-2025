#pragma once
#include <vector>
#include <string>
#include "product.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"
#include "HouseholdProduct.h"

class Supermarket {
    std::vector<product*> ds;

public:
    Supermarket();
    ~Supermarket();

    bool taiTuFile(const std::string& file);
    bool luuVaoFile(const std::string& file) const;

    bool them_sp(product* p);
    product* timTheoMa(const std::string& ma) const;
    bool xoa_sp(const std::string& ma);

    std::vector<product*> layTatCa() const;
    bool giamSoLuong(const std::string& ma, int sl);

};

