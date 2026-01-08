#pragma once
#include "product.h"
#include <vector>
#include <string>

class Cart {
public:
    struct MucGio {
        std::string maSP;
        product* SPptr;
        int Soluong;
        double price;

        MucGio() : SPptr(nullptr), Soluong(0), price(0.0) {}
        MucGio(product* sp, int sl)
            : SPptr(sp), Soluong(sl), price(sp ? sp->getprice() : 0.0) {
            if (sp) maSP = sp->getid();
        }
    };

    std::vector<MucGio> danhSach;

    bool them(product* p, int so_luong);
    bool xoa(const std::string& id);
    bool thay_sl(const std::string& id, int so_luong_moi);

    // Đánh dấu const nếu header muốn coi đây là hàm không sửa trạng thái
    double tong_tien() const;
};
