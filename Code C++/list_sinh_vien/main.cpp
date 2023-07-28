#include <iostream>
#include <string>
#include <cassert>
#include <list>

using namespace std;

typedef enum {
    NU,
    NAM
}TypeGioiTinh;

typedef enum {
    GIOI ,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class SinhVien{
    private:
    int ID;
    string Ten;  //property
    int Tuoi;
    string Gioi_Tinh;
    TypeHocLuc Hoc_Luc;
    double Diem_Toan;
    double Diem_Ly;
    double Diem_Hoa;
    double Diem_TB;
    public:
    SinhVien(string ten, int tuoi, string gioi_tinh, double diem_toan, double diem_ly, double diem_hoa);
    void hienthi();
    int hienthi_ID();
    string hienthi_ten();
    double hienthi_diemtb();
    void suathongtin(string ten, int tuoi, string gioi_tinh, double diem_toan, double diem_ly, double diem_hoa);
};

SinhVien::SinhVien(string ten, int tuoi, string gioi_tinh, double diem_toan, double diem_ly, double diem_hoa){
    static int id = 1000;
    ID = id;
    id++;
    Ten = ten;
    Tuoi = tuoi;
    Gioi_Tinh = gioi_tinh;
    Diem_Toan = diem_toan;
    assert((diem_toan >= 0 && diem_toan <= 10) && "diem toan khong hop le");
    Diem_Hoa = diem_hoa;
    assert((diem_hoa >= 0 && diem_hoa <= 10) && "diem hoa khong hop le");
    Diem_Ly = diem_ly;
    assert((diem_ly >= 0 && diem_ly <= 10) && "diem ly khong hop le");
    Diem_TB = (Diem_Hoa + Diem_Ly + Diem_Toan)/3;
    if (Diem_TB >= 8)
    {
        Hoc_Luc = GIOI;
    } else if (Diem_TB >= 6.5)
    {
        Hoc_Luc = KHA;
    } else if (Diem_TB >= 5)
    {
        Hoc_Luc = TRUNG_BINH;
    } else {
        Hoc_Luc = YEU;
    }
}

void SinhVien::hienthi(){
    string temp;
    if (Hoc_Luc == 0)
    {
        temp = "GIOI";
    } else if (Hoc_Luc == 1)
    {
        temp = "KHA";
    } else if (Hoc_Luc == 2)
    {
        temp = "TRUNG_BINH";
    } else {
        temp = "YEU";
    }
    
    cout<<"---------------------------------------"<<endl;
    cout<<"Ten sinh vien: "<<Ten<<endl;
    cout<<"Ma so sinh vien: "<<ID<<endl;
    cout<<"Tuoi sinh vien: "<<Tuoi<<endl;
    cout<<"Gioi tinh sinh vien: "<<Gioi_Tinh<<endl;
    cout<<"Diem toan: "<<Diem_Toan<<endl;
    cout<<"Diem ly: "<<Diem_Ly<<endl;
    cout<<"Diem hoa: "<<Diem_Hoa<<endl;
    cout<<"Diem trung binh: "<<Diem_TB<<endl;
    cout<<"Hoc luc: "<<temp<<endl;    
}

int SinhVien::hienthi_ID(){
    return ID;
}

string SinhVien::hienthi_ten(){
    return Ten;
}

double SinhVien::hienthi_diemtb(){
    return Diem_TB;
}

void SinhVien::suathongtin(string ten, int tuoi, string gioi_tinh, double diem_toan, double diem_ly, double diem_hoa){
    Ten = ten;
    Tuoi = tuoi;
    Gioi_Tinh = gioi_tinh;
    Diem_Toan = diem_toan;
    Diem_Hoa = diem_hoa;
    Diem_Ly = diem_ly;
    Diem_TB = (Diem_Hoa + Diem_Ly + Diem_Toan)/3;
    if (Diem_TB >= 8)
    {
        Hoc_Luc = GIOI;
    } else if (Diem_TB >= 6.5)
    {
        Hoc_Luc = KHA;
    } else if (Diem_TB >= 5)
    {
        Hoc_Luc = TRUNG_BINH;
    } else {
        Hoc_Luc = YEU;
    }
}


void themsinhvien(list <SinhVien> &database){
    string Ten; 
    int Tuoi;
    string Gioi_Tinh;
    double Diem_Toan;
    double Diem_Ly;
    double Diem_Hoa;

    do
    {
        cout<<"Nhap ten sinh vien: "<<endl;
        fflush(stdin);
        getline(cin,Ten);
    } while (Ten == "\0");

    do
    {
        cout<<"Nhap tuoi sinh vien: "<<endl;
        cin>>Tuoi;
    } while (Tuoi <= 0);

    do
    {
        cout<<"Nhap gioi tinh (NAM hoac NU):"<<endl;
        cin>>Gioi_Tinh;
    } while (Gioi_Tinh != "NAM" && Gioi_Tinh != "NU");
    
    do
    {
        cout<<"Nhap diem toan: "<<endl;
        cin>>Diem_Toan;
    } while (Diem_Toan < 0 || Diem_Toan > 10); 
    
    do
    {
        cout<<"Nhap diem ly: "<<endl;
        cin>>Diem_Ly;
    } while (Diem_Ly < 0 || Diem_Ly > 10);
    
    do
    {
        cout<<"Nhap diem hoa: "<<endl;
        cin>>Diem_Hoa;
    } while (Diem_Hoa < 0 || Diem_Hoa > 10);

    SinhVien sv(Ten,Tuoi,Gioi_Tinh,Diem_Toan,Diem_Ly,Diem_Hoa);
    database.push_back(sv);
}

void capnhat(list<SinhVien> &database){
    int id;
    list<SinhVien>::iterator it;
    string Ten; 
    int Tuoi;
    string Gioi_Tinh;
    double Diem_Toan;
    double Diem_Ly;
    double Diem_Hoa;

    do
    {
        cout<<"Nhap id: "<<endl;
        cin>>id;
    } while (id < 1000);
    
    for ( it = database.begin(); it != database.end(); it++)
    {
        if (it->hienthi_ID() == id)
        {
            do
            {
                cout<<"Nhap ten sinh vien: "<<endl;
                fflush(stdin);
                getline(cin,Ten);
            } while (Ten == "\0");
            
            do
            {
                cout<<"Nhap tuoi sinh vien: "<<endl;
                cin>>Tuoi;
            } while (Tuoi <= 0);
            
            do
            {
                cout<<"Nhap gioi tinh (NAM hoac NU): "<<endl;
                cin>>Gioi_Tinh;
            } while (Gioi_Tinh != "NAM" && Gioi_Tinh != "NU");

            do
            {
                cout<<"Nhap diem toan: "<<endl;
                cin>>Diem_Toan;
            } while (Diem_Toan < 0 || Diem_Toan > 10); 
    
            do
            {
                cout<<"Nhap diem ly: "<<endl;
                cin>>Diem_Ly;
            } while (Diem_Ly < 0 || Diem_Ly > 10);
    
            do
            {
                cout<<"Nhap diem hoa: "<<endl;
                cin>>Diem_Hoa;
            } while (Diem_Hoa < 0 || Diem_Hoa > 10);
            it->suathongtin(Ten,Tuoi,Gioi_Tinh,Diem_Toan,Diem_Ly,Diem_Hoa);
            break;
        }
    
    }
    
    cout<<"khong co ma so sinh vien tren"<<endl;

}

void xoasinhvien(list<SinhVien> &database){
    int id;
    int i = 0;
    list<SinhVien>::iterator it;
   
    do
    {
        cout<<"Nhap id: "<<endl;
        cin>>id;
    } while (id < 1000);   

    for ( it = database.begin(); it != database.end(); it++)
    {
        if (it->hienthi_ID() == id)
        {
            database.erase(it);
            i++;
        }
    }
    if (i == 0)
    {
        cout<<"khong co ma so sinh vien tren"<<endl;
    }
    

}

void timtheoten(list<SinhVien> &database){
    string ten;
    int i = 0;
    list<SinhVien>::iterator it;
    do
    {
        cout<<"Nhap ten sinh vien can tim: "<<endl;
        fflush(stdin);
        getline(cin,ten);
    } while (ten == "\0");   

    for ( it = database.begin(); it != database.end(); it++)
    {
        if (it->hienthi_ten() == ten)
        {
            it->hienthi();
            i++;
        }
    }
    if (i == 0)
    {
        cout<<"khong co sinh vien ten: "<<ten<<endl;
    }

}



void hienthi_database(list<SinhVien> &database){
    for (SinhVien i : database)
    {
        i.hienthi();
    }
}



int main(int argc, char const *argv[])
{
    list <SinhVien> database;
    int input;
    while (1)
    {
        cout<<"Chuong trinh tao danh sach sinh vien"<<endl;
        cout<<"Nhap 0 de ket thuc chuong trinh"<<endl;
        cout<<"Nhap 1 de  them sinh vien"<<endl;
        cout<<"Nhap 2 de  cap nhat thong tin sinh vien theo ID"<<endl;
        cout<<"Nhap 3 de xoa sinh vien theo ID"<<endl;
        cout<<"Nhap 4 de tim kiem sinh vien theo ten"<<endl;   
        cout<<"Nhap 7 de hien thi danh sach sinh vien"<<endl;
        cout<<"Nhap input: "<<endl;
        cin>>input;
        if (input == 0)
        {
            break;
        } else if (input == 1)
            {
                themsinhvien(database);
            } else if (input == 2)
            {
                capnhat(database);
            } else if (input == 3)
            {
                xoasinhvien(database);
            } else if (input == 4)
            {
                timtheoten(database);
            } else if (input == 7)
            {
                hienthi_database(database);
            }
        
    }
    
    return 0;
}
