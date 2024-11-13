#include "DanhSachPhuongTien.hpp"
#include <iostream>

using namespace std;

void Menu() {
    cout << "1. Nhap danh sach phuong tien" << endl;
    cout << "2. Xuat danh sach phuong tien" << endl;
    cout << "3. Cap nhat thoi gian ra" << endl;
    cout << "4. Tim kiem phuong tien theo bien so" << endl;
    cout << "5. Tim kiem phuong tien theo thoi gian vao bai" << endl;
    cout << "6. Tim kiem phuong tien dang gui" << endl;
    cout << "7. Hien thi top 3 phuong tien gui nhieu nhat" << endl;
    cout << "8. Thoat" << endl;
}

int main() {
    DanhSachPhuongTien dsPhuongTien;
    int chon;
    do {
        Menu();
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch (chon) {
            case 1:
                dsPhuongTien.NhapDanhSach();
                break;
            case 2:
                dsPhuongTien.XuatDanhSach();
                break;
            case 3: {
                string bienSo;
                ThoiGian thoiGianRa;
                cout << "Nhap bien so: ";
                cin >> bienSo;
                cout << "Nhap thoi gian ra: " << endl;
                cin >> thoiGianRa;
                dsPhuongTien.CapNhatThoiGianRa(bienSo, thoiGianRa);
                break;
            }
            case 4: {
                string bienSoTimKiem;
                cout << "Nhap bien so can tim: ";
                cin >> bienSoTimKiem;
                dsPhuongTien.TimKiem(bienSoTimKiem);
                break;
            }
            case 5: {
                cout << "Nhap thoi gian vao bai can tim: " << endl;
                int ngay, thang, nam;
                cout << "Nhap ngay: ";
                cin >> ngay;
                cout << "Nhap thang: ";
                cin >> thang;
                cout << "Nhap nam: ";
                cin >> nam;
                dsPhuongTien.TimKiem(ngay, thang, nam);
                break;
            }
            case 6:
                dsPhuongTien.TimKiemPhuongTienDangGui();
                break;
            case 7:
                dsPhuongTien.HienthiTop3PhuongTienGuiNhieuNhat();
                break;
            case 8:
                break;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
        }
    } while (chon != 8);
    return 0;
}