
#include "QuanLyDaySo.hpp"
#include <iostream>

using namespace std;

int main() {
    QuanLyDaySo quanLyDaySo;
    int choice;
    do {
        cout << "\n1. Tao danh sach so\n"
                "2. Them phan tu vao danh sach voi vi tri tu chon\n"
                "3. So luong phan tu bang k\n"
                "4. Kiem tra co bo ba so chan duong canh nhau\n"
                "5. Sap xep day so tang dan\n"
                "6. Xoa tat ca cac so nguyen to\n"
                "7. Xoa phan tu trung nhau\n"
                "8. Xuat danh sach so\n"
                "0. Thoat\n"

                "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
            case 1:
                quanLyDaySo.TaoDanhSachSo();
                break;
            case 2:
                quanLyDaySo.ThemPhanTuVaoDanhSach_voiVitriTuChon();
                break;
            case 3:
                cout << "So luong phan tu bang k: " << quanLyDaySo.SoLuongPhanTu_BangK() << endl;
                break;
            case 4:
                if (!quanLyDaySo.KiemtraCoBoBaSoChanDuong_CanhNhau()) {
                    cout << "Khong co bo ba so chan duong canh nhau" << endl;
                }
                break;
            case 5:
                quanLyDaySo.SapXepDaySo_TangDan();
                break;
            case 6:
                quanLyDaySo.XoaTatCaCacSoNguyenTo();
                break;
            case 7:
                quanLyDaySo.XoaPhanTuTrungNhau();
                break;
            case 8:
                quanLyDaySo.XuatDanhSachSo();
                break;
            case 0:
                cout << "Ket thuc chuong trinh" << endl;
                break;
            default:
                cout << "Chuc nang khong ton tai" << endl;
                break;
        }
    } while (choice != 0);
    return 0;
}