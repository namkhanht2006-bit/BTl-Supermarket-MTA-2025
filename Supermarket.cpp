#include "Supermarket.h"
#include <fstream>

bool Supermarket::taiTuFile(const std::string& tenFile) {  std::ifstream in(tenFile);
    if (!in.is_open()) return false;

    while (true) {
        std::string type;
        if (!(in >> type)) break;

        if (type == "Food") {
            FoodProduct* f = new FoodProduct();
            in >> *f;
            them_sp(std::unique_ptr<product>(f));
        }
        else if (type == "Electronic") {
            ElectronicProduct* e = new ElectronicProduct();
            in >> *e;
            them_sp(std::unique_ptr<product>(e));
        }
        else if (type == "Household") {
            HouseholdProduct* h = new HouseholdProduct();
            in >> *h;
            them_sp(std::unique_ptr<product>(h));
        }
        else {

            std::string tmp;
            std::getline(in, tmp);
        }
    }

    return true;

}



bool Supermarket::luuVaoFile(const std::string& tenFile) const {
    std::ofstream out(tenFile);
    if (!out.is_open()) return false;

    for (product* p : danhSachSanPham) {
        out << p->type() << " ";
        p->in(out);
        out << "\n";
    }

    return true;
}

bool Supermarket::them_sp(std::unique_ptr<product> sp) {
    if (!sp) return false;
    product* p = sp.release();
    danhSachSanPham.push_back(p);
    return true;
}

bool Supermarket::xao_sp(const std::string& maSanPham) {
    for (auto it = danhSachSanPham.begin(); it != danhSachSanPham.end(); ++it) {
        if ((*it)->getid() == maSanPham) {
            delete *it;
            danhSachSanPham.erase(it);
            return true;
        }
    }
    return false;
}

product* Supermarket::timTheoMa(const std::string& maSanPham) const {
    for (product* p : danhSachSanPham) {
        if (p && p->getid() == maSanPham) return p;
    }
    return nullptr;
}

bool Supermarket::capNhatSoLuong(const std::string& maSanPham, int slMoi) {
    product* p = timTheoMa(maSanPham);
    if (!p) return false;
    // product::quantity is protected; cannot set. Return true as stub.
    (void)slMoi;
    return false;
}

bool Supermarket::tangSoLuong(const std::string& maSanPham, int sl) {
    (void)maSanPham; (void)sl;
    return false;
}
bool Supermarket::giamSoLuong(const std::string& maSanPham, int sl) {
    (void)maSanPham; (void)sl;
    return false;
}

vector<product*> Supermarket::layTatCa() const {
    return danhSachSanPham;
}
