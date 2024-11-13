//
// Created by admin on 11/13/2024.
//

#ifndef PHANA_DANHSACHPHUONGTIEN_HPP
#define PHANA_DANHSACHPHUONGTIEN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "PhuongTien.hpp"
#include "ThoiGian.hpp"

using namespace std;

class DanhSachPhuongTien {
private:
    vector<PhuongTien> dsPhuongTien;
public:
    DanhSachPhuongTien();
    void ThemPhuongTien(PhuongTien pt);
    void NhapDanhSach();
    void XuatDanhSach();
    void CapNhatThoiGianRa(string bienSo, ThoiGian thoiGianRa);
    void TimKiem(string bienSo);
    void TimKiem(int ngay, int thang, int nam);
    void TimKiemPhuongTienDangGui();
    void HienthiTop3PhuongTienGuiNhieuNhat();
};

bool KiemTraPhuongTienDaTonTai(vector<PhuongTien> dsPhuongTien, string bienSo, ThoiGian thoiGianVao) {
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        if (dsPhuongTien[i].getBienSo() == bienSo) {
            if(dsPhuongTien[i].getThoiGianRa().SoSanh(thoiGianVao) == -1) {
                return false;
            }
            return true;
        }
    }
    return false;
}

DanhSachPhuongTien::DanhSachPhuongTien() {
    dsPhuongTien = vector<PhuongTien>();
}

void DanhSachPhuongTien::ThemPhuongTien(PhuongTien pt) {
    dsPhuongTien.push_back(pt);
}

void DanhSachPhuongTien::NhapDanhSach() {
    int n;
    cout << "Nhap so luong phuong tien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        PhuongTien pt;
        cin >> pt;
        if(KiemTraPhuongTienDaTonTai(dsPhuongTien, pt.getBienSo(), pt.getThoiGianVaoBai())) {
            cout << "Phuong tien da ton tai" << endl;
            i--;
        } else {
            ThemPhuongTien(pt);
        }
    }
}

void DanhSachPhuongTien::XuatDanhSach() {
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        cout << dsPhuongTien[i] << endl;
    }
}

void DanhSachPhuongTien::TimKiem(string bienSo) {
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        if (dsPhuongTien[i].getBienSo() == bienSo) {
            if (dsPhuongTien[i].getThoiGianRa().SoSanh(ThoiGian()) == 1) {
                cout << dsPhuongTien[i] << endl;
                return;
            }
        }
    }
    cout << "Khong tim thay phuong tien" << endl;
}

void DanhSachPhuongTien::TimKiem(int ngay, int thang, int nam) {
    ThoiGian tg(0, 0, 0, ngay, thang, nam);
    if (!KiemtraThoiGianHopLe(0, 0, 0, tg.getNgay(), tg.getThang(), tg.getNam())) {
        cout << "Thoi gian khong hop le" << endl;
        return;
    }
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        if (dsPhuongTien[i].getThoiGianVaoBai().getNgay() == ngay
        && dsPhuongTien[i].getThoiGianVaoBai().getThang() == thang
        && dsPhuongTien[i].getThoiGianVaoBai().getNam() == nam){
            cout << dsPhuongTien[i] << endl;
        }
    }
}

void DanhSachPhuongTien::TimKiemPhuongTienDangGui() {
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        if (dsPhuongTien[i].getThoiGianRa().SoSanh(ThoiGian()) == 0) {
            cout << dsPhuongTien[i] << endl;
        }
    }
}

void DanhSachPhuongTien::HienthiTop3PhuongTienGuiNhieuNhat() {
    vector<int> SoLanGui(dsPhuongTien.size(), 0);
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        for (int j = 0; j < dsPhuongTien.size(); j++) {
            if (dsPhuongTien[i].getBienSo() == dsPhuongTien[j].getBienSo()) {
                SoLanGui[i]++;
            }
        }
    }
    sort(SoLanGui.begin(), SoLanGui.end(), greater<int>());
    for (int i = 0; i < 3; i++) {
        cout << dsPhuongTien[i] << endl;
        cout << "--------------------------------" << endl;
    }
}

void DanhSachPhuongTien::CapNhatThoiGianRa(string bienSo, ThoiGian thoiGianRa) {
    for (int i = 0; i < dsPhuongTien.size(); i++) {
        if (dsPhuongTien[i].getBienSo() == bienSo && dsPhuongTien[i].getThoiGianRa().SoSanh(ThoiGian()) == 0) {
            dsPhuongTien[i].setThoiGianRa(thoiGianRa);
            dsPhuongTien[i].TinhTien();
            return;
        }
    }
    cout << "Khong tim thay phuong tien" << endl;
}

#endif //PHANA_DANHSACHPHUONGTIEN_HPP
