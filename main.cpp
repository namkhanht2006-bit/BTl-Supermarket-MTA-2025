#include <iostream>
#include <sstream>
#include <memory>
#include "Supermarket.h"
#include "FoodProduct.h"
#include "ElectronicProduct.h"
#include "HouseholdProduct.h"
using namespace std;

void showMenu() {
    cout << "\n=== SUPERMARKET MENU ===\n";
    cout << "1. Load products from prrr.txt\n";
    cout << "2. Show all products\n";
    cout << "3. Add product\n";
    cout << "4. Delete product by ID\n";
    cout << "5. Search product by ID\n";
    cout << "6. Save products to file\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int main() {
    Supermarket sm;
    int choice = -1;

    while (choice != 0) {
        showMenu();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        cin.ignore(10000, '\n');

        if (choice == 1) {
            if (sm.taiTuFile("prrr.txt")) cout << "Loaded OK\n";
            else cout << "Load failed\n";
        }
        else if (choice == 2) {
            cout << "---- Products ----\n";
            for (const auto& pptr : sm.layTatCa()) {
                ostringstream oss;
                pptr->in(oss);
                cout << oss.str() << "\n";
            }
        }
        else if (choice == 3) {
            cout << "Choose type (1=FOOD,2=ELECTRONIC,3=HOUSEHOLD): ";
            int t; cin >> t; cin.ignore(10000, '\n');

            string id, name, extra;
            double price; int qty;

            cout << "ID: "; getline(cin, id);
            cout << "Name: "; getline(cin, name);
            cout << "Price: "; cin >> price; cin.ignore(10000, '\n');
            cout << "Quantity: "; cin >> qty; cin.ignore(10000, '\n');

            if (t == 1) {
                cout << "Expiry (YYYY-MM-DD): "; getline(cin, extra);
                auto p = make_unique<FoodProduct>(id, name, price, qty, extra);
                if (sm.them_sp(move(p))) cout << "Added.\n"; else cout << "Add failed (dup id?)\n";
            }
            else if (t == 2) {
                cout << "Warranty (months/text): "; getline(cin, extra);
                auto p = make_unique<ElectronicProduct>(id, name, price, qty, extra);
                if (sm.them_sp(move(p))) cout << "Added.\n"; else cout << "Add failed (dup id?)\n";
            }
            else if (t == 3) {
                cout << "Material: "; getline(cin, extra);
                auto p = make_unique<HouseholdProduct>(id, name, price, qty, extra);
                if (sm.them_sp(move(p))) cout << "Added.\n"; else cout << "Add failed (dup id?)\n";
            }
            else {
                cout << "Invalid type\n";
            }
        }
        else if (choice == 4) {
            string id; cout << "Enter ID to delete: "; getline(cin, id);
            if (sm.xoa_sp(id)) cout << "Deleted.\n"; else cout << "Not found.\n";
        }
        else if (choice == 5) {
            string id; cout << "Enter ID to search: "; getline(cin, id);
            product* p = sm.timTheoMa(id);
            if (p) {
                ostringstream oss; p->in(oss); cout << oss.str() << "\n";
            }
            else cout << "Not found\n";
        }
        else if (choice == 6) {
            if (sm.luuVaoFile("prrr_out.txt")) cout << "Saved to prrr_out.txt\n";
            else cout << "Save failed\n";
        }
    }

    cout << "Bye\n";
    return 0;
}
