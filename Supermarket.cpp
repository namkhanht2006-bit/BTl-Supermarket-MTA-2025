#include "Supermarket.h"
#include <fstream>

Supermarket::Supermarket() {}

Supermarket::~Supermarket() {
    for (product* p : ds)
        delete p;
}

bool Supermarket::them_sp(product* p) {
    if (!p) return false;
    ds.push_back(p);
    return true;
}

product* Supermarket::timTheoMa(const std::string& ma) const {
    for (product* p : ds)
        if (p->getid() == ma)
            return p;
    return nullptr;
}

bool Supermarket::xoa_sp(const std::string& ma) {
    for (auto it = ds.begin(); it != ds.end(); ++it) {
        if ((*it)->getid() == ma) {
            delete *it;
            ds.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<product*> Supermarket::layTatCa() const {
    return ds;
}

bool Supermarket::taiTuFile(const std::string& file) {
    std::ifstream in(file);
    if (!in) return false;

    while (true) {
        std::string type;
        if (!(in >> type)) break;

        product* p = nullptr;
        if (type == "Food") p = new FoodProduct();
        else if (type == "Electronic") p = new ElectronicProduct();
        else if (type == "Household") p = new HouseholdProduct();
        else { std::string skip; std::getline(in, skip); continue; }

        in >> *p;
        ds.push_back(p);
    }
    return true;
}

bool Supermarket::luuVaoFile(const std::string& file) const {
    std::ofstream out(file);
    if (!out) return false;

    for (product* p : ds) {
        out << p->type() << " ";
        p->in(out);
        out << "\n";
    }
    return true;
}
bool Supermarket::giamSoLuong(const std::string& ma, int sl) {
    if (sl <= 0) return false;
    product* p = timTheoMa(ma);
    if (!p) return false;

    int cur = p->getquantity();
    if (cur < sl) return false;

    p->setquantity(cur - sl);
    return true;
}
