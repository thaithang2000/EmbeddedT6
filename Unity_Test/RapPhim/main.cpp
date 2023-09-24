#include "pch.h"
// Quan ly dat ve xem phim
// Them phim moi
// Danh sach phim
// Dat ve cho mot phim
// Kiem tra suc chua rap phim

#include <string>
#include <vector>
using namespace std;

enum class LoaiPhong {
    LOAI_THUONG = 0,
    LOAI_TRUNG,
    LOAI_VIP,
    LOAI_VVIP
};

class Phim {
public:
    Phim(string ten, LoaiPhong loai);
    string getTen();
    LoaiPhong getLoaiPhong();
    int getSoVeDaDat();
    int getSoVeConLai();
    bool datVe(int soLuong);
    int getMaxSoVe();
private:
    string ten;
    LoaiPhong loai;
    int soVeDaDat;
    int MaxSoVe;
};

Phim::Phim(string ten, LoaiPhong loai) : ten(ten), loai(loai), soVeDaDat(0) {
    switch (loai)
    {
    case LoaiPhong::LOAI_THUONG:
        MaxSoVe = 50;
        break;
    case LoaiPhong::LOAI_TRUNG:
        MaxSoVe = 100;
        break;
    case LoaiPhong::LOAI_VIP:
        MaxSoVe = 150;
        break;
    default:
        MaxSoVe = 0;
        break;
    }
}

string Phim::getTen() {
    return ten;
}

LoaiPhong Phim::getLoaiPhong() {
    return loai;
}

int Phim::getSoVeDaDat() {
    return soVeDaDat;
}

int Phim::getSoVeConLai() {
    return getMaxSoVe() - getSoVeDaDat();
}

bool Phim::datVe(int soLuong) {
    if (soLuong <= 0 || soLuong > getSoVeConLai()) {
        return false;
    }

    soVeDaDat += soLuong;
    return true;
}

int Phim::getMaxSoVe() {
    return MaxSoVe;
    
}
TEST(RapPhimTest, ThemPhimMoi) {
    Phim PhimA("A", LoaiPhong::LOAI_THUONG);
    vector<Phim> database;
    database.push_back(PhimA);
    EXPECT_EQ(database.size(), 1);

}

TEST(RapPhimTest, LayThongTinPhim) {
    Phim PhimA("A", LoaiPhong::LOAI_THUONG);
    vector<Phim> database;
    database.push_back(PhimA);
    EXPECT_EQ(PhimA.getTen(), "A");
    EXPECT_EQ(PhimA.getLoaiPhong(), LoaiPhong::LOAI_THUONG);
    EXPECT_EQ(PhimA.getSoVeDaDat(), 0);
    EXPECT_EQ(PhimA.getMaxSoVe(), 50);
    EXPECT_EQ(PhimA.getSoVeConLai(), 50);
}


TEST(RapPhimTest, DatVe) {
    Phim PhimA("A", LoaiPhong::LOAI_THUONG);
    vector<Phim> database;
    database.push_back(PhimA);
    EXPECT_EQ(PhimA.datVe(-1), false);
    EXPECT_EQ(PhimA.datVe(51), false);
    EXPECT_EQ(PhimA.datVe(10), true);
    EXPECT_EQ(PhimA.getSoVeDaDat(), 10);
    EXPECT_EQ(PhimA.getSoVeConLai(), 50 - PhimA.getSoVeDaDat());
}

TEST(RapPhimTest, LoaiPhong) {
    Phim PhimA("A", LoaiPhong::LOAI_THUONG);
    Phim PhimB("B", LoaiPhong::LOAI_TRUNG);
    Phim PhimC("C", LoaiPhong::LOAI_VIP);
    Phim PhimD("D", LoaiPhong::LOAI_VVIP);

    EXPECT_EQ(PhimA.getMaxSoVe(), 50);
    EXPECT_EQ(PhimB.getMaxSoVe(), 100);
    EXPECT_EQ(PhimC.getMaxSoVe(), 150);
    EXPECT_EQ(PhimD.getMaxSoVe(), 0);
}