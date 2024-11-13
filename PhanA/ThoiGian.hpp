//
// Created by admin on 11/13/2024.
//

#ifndef PHANA_THOIGIAN_HPP
#define PHANA_THOIGIAN_HPP

#include <iostream>
#include <string>

using namespace std;

class ThoiGian {
private:
    int gio;
    int phut;
    int giay;
    int ngay;
    int thang;
    int nam;
public:
    ThoiGian();
    ThoiGian(int gio, int phut, int giay, int ngay, int thang, int nam);
    ThoiGian getThoiGian();
    int TinhKhoangCach(ThoiGian tg2);
    int SoSanh(ThoiGian tg2);
    int getNgay();
    int getThang();
    int getNam();

    friend istream& operator>>(istream& is, ThoiGian &tg);
    friend ostream& operator<<(ostream& os, ThoiGian tg);
};

ThoiGian::ThoiGian() {
    gio = 0;
    phut = 0;
    giay = 0;
    ngay = 0;
    thang = 0;
    nam = 0;
}

ThoiGian::ThoiGian(int gio, int phut, int giay, int ngay, int thang, int nam) {
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

bool KiemtraThoiGianHopLe(int gio, int phut, int giay, int ngay, int thang, int nam) {
    if (gio < 0 || gio > 23) {
        return false;
    }
    if (phut < 0 || phut > 59) {
        return false;
    }
    if (giay < 0 || giay > 59) {
        return false;
    }
    if (ngay < 1 || ngay > 31) {
        return false;
    }
    if (thang < 1 || thang > 12) {
        return false;
    }
    if (nam < 0) {
        return false;
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        if (ngay > 30) {
            return false;
        }
    }
    if (thang == 2) {
        if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) {
            if (ngay > 29) {
                return false;
            }
        } else {
            if (ngay > 28) {
                return false;
            }
        }
    }
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        if (ngay > 31) {
            return false;
        }
    }
    return true;
}

ThoiGian ThoiGian::getThoiGian() {
    return ThoiGian(gio, phut, giay, ngay, thang, nam);
}

int ThoiGian::TinhKhoangCach(ThoiGian tg2) {
    int khoangCach = 0;
    if (nam == tg2.nam) {
        if (thang == tg2.thang) {
            if (ngay == tg2.ngay) {
                if (gio == tg2.gio) {
                    if (phut == tg2.phut) {
                        khoangCach = giay - tg2.giay;
                    } else {
                        khoangCach = (phut - tg2.phut) * 60 + giay - tg2.giay;
                    }
                } else {
                    khoangCach = (gio - tg2.gio) * 3600 + (phut - tg2.phut) * 60 + giay - tg2.giay;
                }
            } else {
                khoangCach = (ngay - tg2.ngay) * 86400 + (gio - tg2.gio) * 3600 + (phut - tg2.phut) * 60 + giay - tg2.giay;
            }
        } else {
            khoangCach = (thang - tg2.thang) * 2592000 + (ngay - tg2.ngay) * 86400 + (gio - tg2.gio) * 3600 + (phut - tg2.phut) * 60 + giay - tg2.giay;
        }
    } else {
        khoangCach = (nam - tg2.nam) * 31536000 + (thang - tg2.thang) * 2592000 + (ngay - tg2.ngay) * 86400 + (gio - tg2.gio) * 3600 + (phut - tg2.phut) * 60 + giay - tg2.giay;
    }
    // Trả về khoảng cách giờ
    return khoangCach / 3600;
}

istream& operator>>(istream& is, ThoiGian &tg) {
    do {
        cout << "Nhap gio: ";
        is >> tg.gio;
        cout << "Nhap phut: ";
        is >> tg.phut;
        cout << "Nhap giay: ";
        is >> tg.giay;
        cout << "Nhap ngay: ";
        is >> tg.ngay;
        cout << "Nhap thang: ";
        is >> tg.thang;
        cout << "Nhap nam: ";
        is >> tg.nam;
    } while (!KiemtraThoiGianHopLe(tg.gio, tg.phut, tg.giay, tg.ngay, tg.thang, tg.nam));
    return is;
}

ostream& operator<<(ostream& os, ThoiGian tg) {
    os << tg.gio << ":" << tg.phut << ":" << tg.giay << " " << tg.ngay << "/" << tg.thang << "/" << tg.nam;
    return os;
}

int ThoiGian::SoSanh(ThoiGian tg2) {
    // So sánh theo thứ tự năm, tháng, ngày, giờ, phút, giây, trả về 1 nếu thời gian hiện tại lớn hơn thời gian tg2
    // Trả về 0 nếu bằng nhau
    // Trả về -1 nếu nhỏ hơn
    if (nam > tg2.nam) {
        return 1;
    } else if (nam < tg2.nam) {
        return -1;
    } else {
        if (thang > tg2.thang) {
            return 1;
        } else if (thang < tg2.thang) {
            return -1;
        } else {
            if (ngay > tg2.ngay) {
                return 1;
            } else if (ngay < tg2.ngay) {
                return -1;
            } else {
                if (gio > tg2.gio) {
                    return 1;
                } else if (gio < tg2.gio) {
                    return -1;
                } else {
                    if (phut > tg2.phut) {
                        return 1;
                    } else if (phut < tg2.phut) {
                        return -1;
                    } else {
                        if (giay > tg2.giay) {
                            return 1;
                        } else if (giay < tg2.giay) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

int ThoiGian::getNgay() {
    return ngay;
}

int ThoiGian::getThang() {
    return thang;
}

int ThoiGian::getNam() {
    return nam;
}

#endif //PHANA_THOIGIAN_HPP
