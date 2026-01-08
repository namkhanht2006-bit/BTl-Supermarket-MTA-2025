#include <iostream>
#include <string>
#include <vector>

#include "Supermarket.h"
#include "Customer.h"
#include "Order.h"

using namespace std;

void printMenu() {
    cout << "\n ---MENU SIEU--- \n";
    cout << "1. Them san pham (nhap tu ban phim)\n";
    cout << "2. Hien thi tat ca san pham\n";
    cout << "3. Them san pham vao gio (theo ma)\n";
    cout << "4. Xem gio hang\n";
    cout << "5. Checkout\n";
    cout << "6. Tai san pham tu file\n";
    cout << "7. Thoat\n";
    cout << "Lua chon: ";
}

int main() {
    Supermarket sm;
    Customer kh;

    while (true) {
        printMenu();
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            string skip;
            getline(cin, skip);
            cout << "Nhap khong hop le. Thu lai.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Chon loai san pham de nhap:\n";
            cout << "1 - FoodProduct\n2 - ElectronicProduct\n3 - HouseholdProduct\nLua chon: ";
            int t;
            cin >> t;
            cin.ignore();

            if (t == 1) {
                FoodProduct* f = new FoodProduct();
                cout << "Nhap thong tin FoodProduct (theo yeu cau class):\n";
                cin >> *f;
                sm.them_sp(f);
                cout << "Da them FoodProduct vao sieu thi.\n";
            } else if (t == 2) {
                ElectronicProduct* e = new ElectronicProduct();
                cout << "Nhap thong tin ElectronicProduct:\n";
                cin >> *e;
                sm.them_sp(e);
                cout << "Da them ElectronicProduct vao sieu thi.\n";
            } else if (t == 3) {
                HouseholdProduct* h = new HouseholdProduct();
                cout << "Nhap thong tin HouseholdProduct:\n";
                cin >> *h;
                sm.them_sp(h);
                cout << "Da them HouseholdProduct vao sieu thi.\n";
            } else {
                cout << "Lua chon khong hop le.\n";
            }
        }
        else if (choice == 2) {
            cout << "\n--- Danh sach san pham ---\n";
            vector<product*> ds = sm.layTatCa();
            for (size_t i = 0; i < ds.size(); ++i) {
                product* p = ds[i];
                if (p != NULL) {
                    cout << *p << "\n";
                }
            }
        }
        else if (choice == 3) {
            string ma;
            int soLuong;
            cout << "Nhap ma san pham can them vao gio: ";
            cin >> ma;
            cout << "Nhap so luong: ";
            cin >> soLuong;
            product* p = sm.timTheoMa(ma);
            if (p == NULL) {
                cout << "Khong tim thay san pham co ma " << ma << "\n";
            } else {
                bool ok = kh.getCart().them(p, soLuong);
                if (ok) cout << "Da them vao gio: " << ma << " SL=" << soLuong << "\n";
                else cout << "Them vao gio that bai (co the la so luong khong hop le)\n";
            }
        }
        else if (choice == 4) {
            cout << "\n--- Gio hang cua khach ---\n";
            const Cart& cartref = kh.getCart();
            for (size_t i = 0; i < cartref.danhSach.size(); ++i) {
                const Cart::MucGio& mg = cartref.danhSach[i];
                cout << "MaSP: " << mg.maSP
                     << " | So luong: " << mg.Soluong
                     << " | Don gia: " << mg.price << "\n";
            }
            cout << "Tong tien: " << kh.getCart().tong_tien() << "\n";
        }
        else if (choice == 5) {
            cout << "Thuc hien checkout...\n";
            string maDon;
            cout << "Nhap ma don (vi du: DH001): ";
            cin >> maDon;

            Order outOrder;
            bool ok = outOrder.Checkout(kh, sm, maDon, outOrder);
            if (ok) {
                cout << "Checkout thanh cong. Hoa don:\n";
                cout << outOrder.toTextHoaDon() << "\n";

                string tenFile = string("HoaDon_") + maDon + string(".txt");
                bool saved = outOrder.ghiRaFile(tenFile);
                if (saved) cout << "Da luu file: " << tenFile << "\n";
                else cout << "Luu file that bai.\n";
            } else {
                cout << "Checkout that bai.\n";
            }
        }
        else if (choice == 6) {
            string filename;
            cout << "Nhap ten file chua danh sach san pham (vi du: products.txt): ";
            cin >> filename;
            bool loaded = sm.taiTuFile(filename);
            if (loaded) {
                cout << "Tai file thanh cong.\n";
            } else {
                cout << "Khong the doc file hoac file rong / chua duoc implement.\n";
                cout << "HINT: neu ham taiTuFile chua duoc implement trong Supermarket.cpp, ban can implement de hoat dong.\n";
            }
        }
        else if (choice == 7) {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        else {
            cout << "Lua chon khong hop le.\n";
        }
    }

    return 0;
}
