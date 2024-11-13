#ifndef QUANLYDAYSO_QUANLYDAYSO_HPP
#define QUANLYDAYSO_QUANLYDAYSO_HPP

#include <iostream>
#include <cmath>
#include "SingleLinkedList.hpp"

using namespace std;

class QuanLyDaySo {
private:
    SingleLinkedList<int> list;
public:
    QuanLyDaySo() = default;
    void TaoDanhSachSo();
    void ThemPhanTuVaoDanhSach_voiVitriTuChon();
    int SoLuongPhanTu_BangK();
    bool KiemtraCoBoBaSoChanDuong_CanhNhau(); // Neu co thi in ra vi tri cua bo ba so do
    void SapXepDaySo_TangDan();
    void XoaTatCaCacSoNguyenTo();
    void XoaPhanTuTrungNhau();
    void XuatDanhSachSo();
};

// Nhap danh sach so, ket thuc khi nhap "#"
void QuanLyDaySo::TaoDanhSachSo() {
    std::string input;
    cout << "Nhap cac phan tu cua danh sach (nhap '#' de dung): ";
    while (true) {
        cin >> input;
        if (input == "#") break;
        int x = stoi(input); // Convert input to integer
        list.addBack(x);
    }
}

// Xuat danh sach so
void QuanLyDaySo::XuatDanhSachSo() {
    cout << "Danh sach so: ";
    for(Node<int>* p = list.getFront(); p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
}

// Them phan tu vao vi tri tu chon
void QuanLyDaySo::ThemPhanTuVaoDanhSach_voiVitriTuChon() {
    int x, k;
    cout << "Nhap phan tu can them: ";
    cin >> x;
    cout << "Nhap vi tri can them: ";
    cin >> k;
    list.addAt(x, k);
    cout << "Da them phan tu " << x << " vao vi tri " << k << endl;
}

// Dem so luong phan tu bang k
int QuanLyDaySo::SoLuongPhanTu_BangK() {
    int k;
    cout << "Nhap so nguyen k: ";
    cin >> k;
    return list.count(k);
}

// Kiem tra co bo ba so chan duong canh nhau va in ra vi tri
bool QuanLyDaySo::KiemtraCoBoBaSoChanDuong_CanhNhau() {
    Node<int>* p = list.getFront();
    int position = 1;
    while (p != nullptr && p->next != nullptr && p->next->next != nullptr) {
        if (p->data % 2 == 0 && p->data > 0 &&
            p->next->data % 2 == 0 && p->next->data > 0 &&
            p->next->next->data % 2 == 0 && p->next->next->data > 0) {
            cout << "Bo ba so chan duong canh nhau tai cac vi tri: "
                 << position << ", " << position + 1 << ", " << position + 2 << endl;
            return true;
        }
        p = p->next;
        position++;
    }
    return false;
}

// Sap xep danh sach tang dan
void QuanLyDaySo::SapXepDaySo_TangDan() {
    list.sort();
}

// Ham kiem tra so nguyen to
bool checkSNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Xoa tat ca cac so nguyen to trong danh sach
void QuanLyDaySo::XoaTatCaCacSoNguyenTo() {
    Node<int>* p = list.getFront();
    while (p != nullptr) {
        if (checkSNT(p->data)) {
            list.remove(p->data);
        }
        p = p->next;
    }
    cout << "Da xoa tat ca cac so nguyen to" << endl;
}

// Xoa phan tu trung nhau, chi giu lai 1 phan tu duy nhat
void QuanLyDaySo::XoaPhanTuTrungNhau() {
    Node<int>* p = list.getFront();
    while (p != nullptr) {
        Node<int>* prev = p;
        Node<int>* q = p->next;
        while (q != nullptr) {
            if (p->data == q->data) {
                Node<int>* duplicate = q;
                prev->next = q->next;  // Xoa node q
                q = q->next;            // Chuyen q sang node tiep theo
                delete duplicate;       // Xoa node duplicate
            } else {
                prev = q;               // Cap nhat prev
                q = q->next;            // Chuyen q sang node tiep theo
            }
        }
        p = p->next;
    }
    cout << "Da xoa phan tu trung nhau" << endl;
}


#endif //QUANLYDAYSO_QUANLYDAYSO_HPP
