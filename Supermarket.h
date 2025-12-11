#pragma once
#include <vector>
#include <memory>
#include <string>
#include "product.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"
#include "HouseholdProduct.h"

class Supermarket {
private:

    std::vector<std::unique_ptr<product>> danhSachSanPham;

public:
    Supermarket() = default;

    Supermarket(const Supermarket&) = delete;
    Supermarket& operator=(const Supermarket&) = delete;

    Supermarket(Supermarket&&) = default;
    Supermarket& operator=(Supermarket&&) = default;

    ~Supermarket() = default;

    bool taiTuFile(const std::string& tenFile);
    bool luuVaoFile(const std::string& tenFile) const;

    bool them_sp(std::unique_ptr<product> sp);
    bool xoa_sp(const std::string& maSanPham);

    product* timTheoMa(const std::string& maSanPham) const;

    bool capNhatSoLuong(const std::string& maSanPham, int slMoi);
    bool tangSoLuong(const std::string& maSanPham, int sl);
    bool giamSoLuong(const std::string& maSanPham, int sl);

    const std::vector<std::unique_ptr<product>>& layTatCa() const {
        return danhSachSanPham;
    }
};

