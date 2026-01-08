#include "Cart.h"
#include <iostream>
using namespace std;

bool  Cart:: them(product* p, int so_luong) {
	if (p == nullptr || so_luong <= 0) {
		return false;
	}
	string id = p->getid();

	for (int i = 0;i < danhSach.size();i++) {
		if (danhSach[i].maSP == id) {
			danhSach[i].Soluong += so_luong;
			return true;
		}
}
	MucGio mg(p, so_luong);
	danhSach.push_back(mg);
	return true;
}
bool Cart::xoa(const string& id) {
	for (auto it = danhSach.begin(); it != danhSach.end();++it) {
		if (it->maSP == id) {
			danhSach.erase(it);
			return true;
		}
	}
	return false;
}
bool Cart::thay_sl(const string& id, int so_luong_moi) {
	if (so_luong_moi < 0) {
		return false;
	}
for(auto it = danhSach.begin(); it != danhSach.end();it++){
	if (it->maSP == id) {
		if (so_luong_moi == 0) {
			danhSach.erase(it);
		}
		else {
			it->Soluong = so_luong_moi;
		}
		return true;
	}

}	
return false;
}
double Cart::tong_tien() const
{
	double tong = 0.0;

	for (int i = 0;i<danhSach.size();i++) {
		if (danhSach[i].SPptr) {
			tong += danhSach[i].SPptr->price_discount(danhSach[i].Soluong);
		}
	}
	return tong;
}
