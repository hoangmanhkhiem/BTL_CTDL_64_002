//
// Created by admin on 11/13/2024.
//

#ifndef PHANA_PHUONGTIEN_HPP
#define PHANA_PHUONGTIEN_HPP

#include <iostream>
#include <string>
#include "ThoiGian.hpp"

using namespace std;

class PhuongTien {
private:
    string tenPhuongTien;
    string hangSanXuat;
    string mauSac;
    string LoaiPhuongTien; // Xe máy = XM, Xe hơi = XH
    string bienSo; // Biển số xe sẽ là khóa chính vì mỗi xe sẽ có một biển số duy nhất
    int phiGuiXe;
    ThoiGian thoiGianvaobai;
    ThoiGian thoiGianra;
public:
    PhuongTien();
    PhuongTien(string tenPhuongTien, string hangSanXuat, string LoaiPhuongTien, string mauSac, string bienSo, ThoiGian thoiGianvaobai, ThoiGian thoiGianra);
    string getTenPhuongTien();
    string getHangSanXuat();
    string getMauSac();
    string getBienSo();
    string getLoaiPhuongTien();
    ThoiGian getThoiGianVaoBai();
    ThoiGian getThoiGianRa();
    int getPhiGuiXe();
    void setThoiGianRa(ThoiGian thoiGianRa);
    int TinhTien();
    // Toán tử cin,cout
    friend istream& operator>>(istream& is, PhuongTien &pt);
    friend ostream& operator<<(ostream& os, PhuongTien pt);
    // Toán tử so sánh
    bool operator < (PhuongTien pt); // So sánh theo thời gian vào bãi

};

PhuongTien::PhuongTien() {
    tenPhuongTien = "";
    hangSanXuat = "";
    mauSac = "";
    LoaiPhuongTien = "";
    bienSo = "";
    phiGuiXe = 0;
    thoiGianvaobai = ThoiGian();
    thoiGianra = ThoiGian();
}

PhuongTien::PhuongTien(string tenPhuongTien, string hangSanXuat, string LoaiPhuongTien, string mauSac, string bienSo, ThoiGian thoiGianvaobai, ThoiGian thoiGianra = ThoiGian()) {
    this->tenPhuongTien = tenPhuongTien;
    this->hangSanXuat = hangSanXuat;
    this->LoaiPhuongTien = LoaiPhuongTien;
    this->mauSac = mauSac;
    this->bienSo = bienSo;
    this->thoiGianvaobai = thoiGianvaobai;
    this->thoiGianra = thoiGianra;
}

string PhuongTien::getTenPhuongTien() {
    return tenPhuongTien;
}

string PhuongTien::getHangSanXuat() {
    return hangSanXuat;
}

string PhuongTien::getMauSac() {
    return mauSac;
}

string PhuongTien::getBienSo() {
    return bienSo;
}

string PhuongTien::getLoaiPhuongTien() {
    return LoaiPhuongTien;
}

ThoiGian PhuongTien::getThoiGianVaoBai() {
    return thoiGianvaobai;
}

ThoiGian PhuongTien::getThoiGianRa() {
    return thoiGianra;
}

void PhuongTien::setThoiGianRa(ThoiGian thoiGianRa) {
    this->thoiGianra = thoiGianRa;
}

int PhuongTien::getPhiGuiXe() {
    return phiGuiXe;
}

int PhuongTien::TinhTien() {
    // Kiểm tra
    if (thoiGianra.SoSanh(ThoiGian()) == 0) {
        return 0;
    }
    int SoGioGuiXe = thoiGianra.TinhKhoangCach(thoiGianvaobai);
    if (SoGioGuiXe == 0) {
        return 0;
    }
    if (LoaiPhuongTien == "XM") {
        phiGuiXe = 5000;
    } else if (LoaiPhuongTien == "XH") {
        phiGuiXe = 20000;
    }
    phiGuiXe *= SoGioGuiXe;
    return 1;
}

istream& operator>>(istream& is, PhuongTien &pt) {
    cout << "Nhap ten phuong tien: ";
    is >> pt.tenPhuongTien;
    cout << "Nhap hang san xuat: ";
    is >> pt.hangSanXuat;
    cout << "Nhap mau sac: ";
    is >> pt.mauSac;
    cout << "Nhap loai phuong tien (XM/XH): ";
    is >> pt.LoaiPhuongTien;
    cout << "Nhap bien so: ";
    is >> pt.bienSo;
    cout << "Nhap thoi gian vao bai: " << endl;
    is >> pt.thoiGianvaobai;
    return is;
}

ostream& operator<<(ostream& os, PhuongTien pt) {
    os << "Ten phuong tien: " << pt.tenPhuongTien << endl;
    os << "Hang san xuat: " << pt.hangSanXuat << endl;
    os << "Mau sac: " << pt.mauSac << endl;
    os << "Loai phuong tien: " << pt.LoaiPhuongTien << endl;
    os << "Bien so: " << pt.bienSo << endl;
    os << "Thoi gian vao bai: " << pt.thoiGianvaobai << endl;
    if(pt.getThoiGianRa().SoSanh(ThoiGian()) != 0) {
        os << "Thoi gian ra: " << pt.getThoiGianRa() << endl;
    }
    else {
        os << "Phuong tien chua ra bai" << endl;
    }
    if(pt.getPhiGuiXe() != 0) {
        os << "Phi gui xe: " << pt.getPhiGuiXe() << endl;
    }
    else {
        os << "Phi gui xe: Chua cap nhat! " << endl;
    }
    return os;
}

bool PhuongTien::operator<(PhuongTien pt) {
    return thoiGianvaobai.SoSanh(pt.thoiGianvaobai);
}


#endif //PHANA_PHUONGTIEN_HPP
