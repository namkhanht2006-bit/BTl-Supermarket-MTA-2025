#include "Supermarket.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"
#include "HouseholdProduct.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

bool Supermarket::taiTuFile(const std::string& tenFile) {
    ifstream fin(tenFile);
    if (!fin.is_open()) {
        cerr << "Cannot open file " << tenFile << endl;
        return false;
    }

    danhSachSanPham.clear();

    string line;
 
    if (!getline(fin, line)) return true;
    if (line.rfind("type", 0) != 0) {
    }
    else {
  
    }

    if (line.rfind("type", 0) == 0) {
       
        while (getline(fin, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string type, id, name, priceS, qtyS, extra;

            if (!getline(ss, type, ',')) continue;
            if (!getline(ss, id, ',')) continue;
            if (!getline(ss, name, ',')) continue;
            if (!getline(ss, priceS, ',')) continue;
            if (!getline(ss, qtyS, ',')) continue;
            if (!getline(ss, extra, ',')) extra = "";

            double price = stod(priceS);
            int qty = stoi(qtyS);

            if (type == "FOOD") {
                auto sp = make_unique<FoodProduct>(id, name, price, qty, extra);
                danhSachSanPham.push_back(move(sp));
            }
            else if (type == "ELECTRONIC") {
                auto sp = make_unique<ElectronicProduct>(id, name, price, qty, extra);
                danhSachSanPham.push_back(move(sp));
            }
            else if (type == "HOUSEHOLD") {
                auto sp = make_unique<HouseholdProduct>(id, name, price, qty, extra);
                danhSachSanPham.push_back(move(sp));
            }
        }
    }
    else {
    
        do {
            if (line.empty()) continue;
            stringstream ss(line);
            string type, id, name, priceS, qtyS, extra;

            if (!getline(ss, type, ',')) continue;
            if (!getline(ss, id, ',')) continue;
            if (!getline(ss, name, ',')) continue;
            if (!getline(ss, priceS, ',')) continue;
            if (!getline(ss, qtyS, ',')) continue;
            if (!getline(ss, extra, ',')) extra = "";

            double price = stod(priceS);
            int qty = stoi(qtyS);

            if (type == "FOOD") {
                auto sp = make_unique<FoodProduct>(id, name, price, qty, extra);
                danhSachSanPham.push_back(move(sp));
            }
            else if (type == "ELECTRONIC") {
                auto sp = make_unique<ElectronicProduct>(id, name, price, qty, extra);
                danhSachSanPham.push_back(move(sp));
            }
            else if (type == "HOUSEHOLD") {
                auto sp = make_unique<HouseholdProduct>(id, name, price, qty, extra);
                danhSachSanPham.push_back(move(sp));
            }
        } while (getline(fin, line));
    }

    fin.close();
    return true;
}

bool Supermarket::luuVaoFile(const std::string& tenFile) const {
    ofstream fout(tenFile);
    if (!fout.is_open()) return false;

    fout << "type,id,name,basePrice,quantity,extra\n";

    for (const auto& sp : danhSachSanPham) {
        ostringstream oss;
        sp->in(oss);
        fout << oss.str() << "\n";
    }

    fout.close();
    return true;
}

bool Supermarket::them_sp(std::unique_ptr<product> sp) {
    if (!sp) return false;
    for (const auto& it : danhSachSanPham) {
        if (it->getId() == sp->getId()) return false; 
    }
    danhSachSanPham.push_back(move(sp));
    return true;
}

bool Supermarket::xoa_sp(const std::string& maSanPham) {
    for (auto it = danhSachSanPham.begin(); it != danhSachSanPham.end(); ++it) {
        if ((*it)->getId() == maSanPham) {
            danhSachSanPham.erase(it);
            return true;
        }
    }
    return false;
}

product* Supermarket::timTheoMa(const std::string& maSanPham) const {
    for (const auto& p : danhSachSanPham) {
        if (p->getId() == maSanPham) return p.get();
    }
    return nullptr;
}

bool Supermarket::capNhatSoLuong(const std::string& maSanPham, int slMoi) {
    product* p = timTheoMa(maSanPham);
    if (!p || slMoi < 0) return false;
    p->setQuantity(slMoi);
    return true;
}

bool Supermarket::tangSoLuong(const std::string& maSanPham, int sl) {
    product* p = timTheoMa(maSanPham);
    if (!p || sl <= 0) return false;
    p->setQuantity(p->getQuantity() + sl);
    return true;
}

bool Supermarket::giamSoLuong(const std::string& maSanPham, int sl) {
    product* p = timTheoMa(maSanPham);
    if (!p || sl <= 0 || p->getQuantity() < sl) return false;
    p->setQuantity(p->getQuantity() - sl);
    return true;
}
