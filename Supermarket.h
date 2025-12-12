#pragma once
#include <vector>
#include <memory>
#include <string>
#include "product.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"
#include "HouseholdProduct.h"
using namespace std;
class Supermarket {
public:

    std::vector<product*> danhSachSanPham;

    Supermarket() = default;
    ~Supermarket() = default;

    bool taiTuFile(const std::string& tenFile);
    bool luuVaoFile(const std::string& tenFile) const;

    bool them_sp(std::unique_ptr<product> sp);
    bool xao_sp(const std::string& maSanPham);

    product* timTheoMa(const std::string& maSanPham) const;

    bool capNhatSoLuong(const std::string& maSanPham, int slMoi);
    bool tangSoLuong(const std::string& maSanPham, int sl);
    bool giamSoLuong(const std::string& maSanPham, int sl);

    vector<product*> layTatCa() const;
};
