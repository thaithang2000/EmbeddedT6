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
    string Ten; 
    int Tuoi;
    TypeGioiTinh Gioi_Tinh;
    TypeHocLuc Hoc_Luc;
    double Diem_Toan;
    double Diem_Ly;
    double Diem_Hoa;
    public:
    SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, double diem_toan, double diem_ly, double diem_hoa);
    int get_ID();
    string get_ten();
    int get_tuoi();
    TypeGioiTinh get_gioitinh();
    double get_diemtoan();
    double get_diemly();
    double get_diemhoa();
    double get_diemtb();
    TypeHocLuc get_hocluc();
    void set_ten(string ten);
    void set_tuoi(int tuoi);
    void set_gioitinh(TypeGioiTinh gioi_tinh);
    void set_diemtoan(double diem_toan);
    void set_diemly(double diem_ly);
    void set_diemhoa(double diem_hoa);    
};

SinhVien::SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, double diem_toan, double diem_ly, double diem_hoa){
    static int id = 1000;
    ID = id;
    id++;
    Ten = ten;
    Tuoi = tuoi;
    if (gioi_tinh == 1)
    {
        Gioi_Tinh = NAM;
    } else {
        Gioi_Tinh = NU;
    }
    
    Diem_Toan = diem_toan;
    assert((diem_toan >= 0 && diem_toan <= 10) && "diem toan khong hop le");
    Diem_Hoa = diem_hoa;
    assert((diem_hoa >= 0 && diem_hoa <= 10) && "diem hoa khong hop le");
    Diem_Ly = diem_ly;
    assert((diem_ly >= 0 && diem_ly <= 10) && "diem ly khong hop le");
}

int SinhVien::get_ID(){
    return ID;
}

string SinhVien::get_ten(){
    return Ten;
}

int SinhVien::get_tuoi(){
    return Tuoi;
}

TypeGioiTinh SinhVien::get_gioitinh(){
    return Gioi_Tinh;
}

double SinhVien::get_diemtoan(){
    return Diem_Toan;
}

double SinhVien::get_diemly(){
    return Diem_Ly;
}

double SinhVien::get_diemhoa(){
    return Diem_Hoa;
}

double SinhVien::get_diemtb(){
    return (Diem_Hoa + Diem_Ly + Diem_Toan)/3;
}

TypeHocLuc SinhVien::get_hocluc(){
    if (get_diemtb() > 8)
    {
        return GIOI;
    } else if (get_diemtb() > 6.5)
    {
        return KHA;
    } else if (get_diemtb() > 5)
    {
        return TRUNG_BINH;
    } else return YEU;
}

void SinhVien::set_ten(string ten){
    Ten = ten;
}

void SinhVien::set_tuoi(int tuoi){
    Tuoi = tuoi;
}

void SinhVien::set_gioitinh(TypeGioiTinh gioi_tinh){
    Gioi_Tinh = gioi_tinh;
}

void SinhVien::set_diemtoan(double diem_toan){
    Diem_Toan = diem_toan;
}

void SinhVien::set_diemly(double diem_ly){
    Diem_Ly = diem_ly;
}

void SinhVien::set_diemhoa(double diem_hoa){
    Diem_Hoa = diem_hoa;
}

void addsinhvien(list <SinhVien> &database){
    string TEN;
    int Tuoi;
    int temp;
    TypeGioiTinh Gioi_Tinh;
    double Diem_Toan;
    double Diem_Ly;
    double Diem_Hoa;

    do
    {
        cout<<"Nhap ten sinh vien: "<<endl;
        cin>>TEN;
    } while (TEN == "\0");

    do
    {
        cout<<"Nhap tuoi sinh vien: "<<endl;
        cin>>Tuoi;
    } while (Tuoi <= 0);

    do
    {
        cout<<"Nhap gioi tinh (NAM = 1 hoac NU = 0):"<<endl;
        cin>>temp;
    } while (temp != 0 && temp != 1);

    switch (temp)
    {
    case 0:
        Gioi_Tinh = NU;
        break;
    case 1:
        Gioi_Tinh = NAM;
        break;    
    default:
        break;
    }
    
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

    SinhVien sv(TEN,Tuoi,Gioi_Tinh,Diem_Toan,Diem_Ly,Diem_Hoa);
    database.push_back(sv);
}

void update(list<SinhVien> &database){
    list<SinhVien>::iterator it;
    int id;
    int input;
    int count = 0;
    string ten;
    int tuoi;
    int temp;
    TypeGioiTinh gioitinh;
    double diem_toan;
    double diem_ly;
    double diem_hoa;
    do
    {
        cout<<"Nhap id: "<<endl;
        cin>>id;
    } while (id < 1000);

    for ( it = database.begin(); it != database.end(); it++)
    {
        if (id == it->get_ID())
        {
            count++;
            cout<<"Thay doi thong tin sinh vien co ma so: "<<id<<endl;
            cout<<"Nhap 1 de sua ten"<<endl;
            cout<<"Nhap 2 de sua tuoi"<<endl;
            cout<<"Nhap 3 de sua gioi tinh"<<endl;
            cout<<"Nhap 4 de sua diem toan"<<endl;   
            cout<<"Nhap 5 de sua diem ly"<<endl;
            cout<<"Nhap 6 de sua diem hoa"<<endl;
            do
            {
                cout<<"Nhap input: "<<endl;
                cin>>input;
            } while (input < 0 && input > 7);

            if (input == 1)
            {
                do
                {
                    cout<<"Nhap ten sinh vien: "<<endl;
                    cin>>ten;
                } while (ten == "\0");
                it->set_ten(ten);
                cout<<"Da sua thong tin thanh cong"<<endl;
                break;
            } else if (input == 2)
            {
                do
                {
                    cout<<"Nhap tuoi sinh vien: "<<endl;
                    cin>>tuoi;
                } while (tuoi <= 0);
                it->set_tuoi(tuoi);
                cout<<"Da sua thong tin thanh cong"<<endl;
                break;
            } else if (input == 3)
            {
                do
                {
                    cout<<"Nhap gioi tinh (NAM = 1 hoac NU = 0):"<<endl;
                    cin>>temp;
                } while (temp != 0 && temp != 1);
                if (temp == 0)
                {
                    gioitinh = NU;
                } else gioitinh = NAM;
                
                it->set_gioitinh(gioitinh);
                cout<<"Da sua thong tin thanh cong"<<endl;
                break;
            } else if (input == 4)
            {
                do
                {
                    cout<<"Nhap diem toan: "<<endl;
                    cin>>diem_toan;
                } while (diem_toan < 0 || diem_toan > 10);
                cout<<"Da sua thong tin thanh cong"<<endl;
                it->set_diemtoan(diem_toan);
                break;
            } else if (input == 5)
            {
                do
                {
                    cout<<"Nhap diem ly: "<<endl;
                    cin>>diem_ly;
                } while (diem_ly < 0 || diem_ly > 10);
                cout<<"Da sua thong tin thanh cong"<<endl;
                it->set_diemly(diem_ly);
                break;
            } else if (input == 6)
            {
                do
                {
                    cout<<"Nhap diem hoa: "<<endl;
                    cin>>diem_hoa;
                } while (diem_hoa < 0 || diem_hoa > 10);
                cout<<"Da sua thong tin thanh cong"<<endl;
                it->set_diemhoa(diem_hoa);
                break;           
            }
            
        }
        
    }
    if (count == 0)
    {
        cout<<"Khong co id: "<<id<<endl;
    }
    
}

void print_sv(list<SinhVien> &database){
    list<SinhVien>::iterator it;
    for (it = database.begin(); it != database.end(); it++)
    {
        cout<<"---------------------------------------"<<endl;
        cout<<"Ten sinh vien: "<<it->get_ten()<<endl;
        cout<<"Ma so sinh vien: "<<it->get_ID()<<endl;
        cout<<"Tuoi "<<it->get_tuoi()<<endl;
        switch (it->get_gioitinh())
        {
            case 0:
            cout<<"Gioi tinh nu"<<endl;
            break;
            case 1:
            cout<<"Gioi tinh nam"<<endl;
            break;
            default:
            break;
        }
        cout<<"Diem toan: "<<it->get_diemtoan()<<endl;
        cout<<"Diem ly: "<<it->get_diemly()<<endl;
        cout<<"Diem hoa: "<<it->get_diemhoa()<<endl;
        cout<<"Diem trung binh: "<<it->get_diemtb()<<endl;
        switch (it->get_hocluc())
        {
            case 0:
            cout<<"Hoc luc gioi"<<endl;
            break;
            case 1:
            cout<<"Hoc luc kha"<<endl;
            break;
            case 2:
            cout<<"Hoc luc trung binh"<<endl;
            break;
            case 3:
            cout<<"Hoc luc yeu"<<endl;        
            break;
            default:
            break;
        }   
    }
    
}

void deletesinhvien(list<SinhVien> &database){
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
        if (it->get_ID() == id)
        {
            cout<<"Da xoa thong tin sinh vien ID: "<<id<<endl;
            database.erase(it);
            i++;
            break;
        }
    }
    if (i == 0)
    {
        cout<<"khong co ma so sinh vien tren"<<endl;
    }
    

}

void namesearching(list<SinhVien> &database){
    string ten;
    int i = 0;
    list<SinhVien>::iterator it;
    do
    {
        cout<<"Nhap ten sinh vien can tim: "<<endl;
        cin>>ten;
    } while (ten == "\0");   

    for ( it = database.begin(); it != database.end(); it++)
    {
        if (it->get_ten() == ten)
        {
            cout<<"---------------------------------------"<<endl;
            cout<<"Ten sinh vien: "<<it->get_ten()<<endl;
            cout<<"Ma so sinh vien: "<<it->get_ID()<<endl;
            cout<<"Tuoi "<<it->get_tuoi()<<endl;
            switch (it->get_gioitinh())
            {
            case 0:
                cout<<"Gioi tinh nu"<<endl;
                break;
            case 1:
                cout<<"Gioi tinh nam"<<endl;
                break;
            default:
                break;
            }
            cout<<"Diem toan: "<<it->get_diemtoan()<<endl;
            cout<<"Diem ly: "<<it->get_diemly()<<endl;
            cout<<"Diem hoa: "<<it->get_diemhoa()<<endl;
            cout<<"Diem trung binh: "<<it->get_diemtb()<<endl;
            switch (it->get_hocluc())
            {
            case 0:
                cout<<"Hoc luc gioi"<<endl;
                break;
            case 1:
                cout<<"Hoc luc kha"<<endl;
                break;
            case 2:
                cout<<"Hoc luc trung binh"<<endl;
                break;
            case 3:
                cout<<"Hoc luc yeu"<<endl;        
                break;
            default:
                break;
            }   
            i++;
        }
    }
    if (i == 0)
    {
        cout<<"khong co sinh vien ten: "<<ten<<endl;
    }

}

void sort_diemtb(list<SinhVien> &database){
    list<SinhVien> temp;
    bool count;
    for (auto i : database)
    {
        count = false;
        for (auto j = temp.begin(); j != temp.end(); j++)
        {
            if (i.get_diemtb() > j->get_diemtb())
            {
                temp.insert(j,i);
                count = true;
                break;
            }  
        }
    
        if (!count)
        {
            temp.push_back(i);
        }
    }    
        for (auto i : temp)
        {
            cout<<"---------Sap xep theo diem trung binh--------"<<endl;
            cout<<"Ten sinh vien: "<<i.get_ten()<<endl;
            cout<<"Ma so sinh vien: "<<i.get_ID()<<endl;
            cout<<"Tuoi "<<i.get_tuoi()<<endl;
            switch (i.get_gioitinh())
            {
            case 0:
                cout<<"Gioi tinh nu"<<endl;
                break;
            case 1:
                cout<<"Gioi tinh nam"<<endl;
                break;
            default:
                break;
            }
            cout<<"Diem toan: "<<i.get_diemtoan()<<endl;
            cout<<"Diem ly: "<<i.get_diemly()<<endl;
            cout<<"Diem hoa: "<<i.get_diemhoa()<<endl;
            cout<<"Diem trung binh: "<<i.get_diemtb()<<endl;
            switch (i.get_hocluc())
            {
            case 0:
                cout<<"Hoc luc gioi"<<endl;
                break;
            case 1:
                cout<<"Hoc luc kha"<<endl;
                break;
            case 2:
                cout<<"Hoc luc trung binh"<<endl;
                break;
            case 3:
                cout<<"Hoc luc yeu"<<endl;        
                break;
            default:
                break;
            }   
        }
    
}


void sort_ten(list<SinhVien> &database){
    list<SinhVien> temp;
    bool count;
    for (auto i : database)
    {
        count = false;
        for (auto j = temp.begin(); j != temp.end(); j++)
        {
            if (i.get_ten() < j->get_ten())
            {
                temp.insert(j,i);
                count = true;
                break;
            }
            
        }
        if (!count)
        {
            temp.push_back(i);
        }
         
    }

    for (auto i : temp)
        {
            cout<<"---------Sap xep theo ten--------"<<endl;
            cout<<"Ten sinh vien: "<<i.get_ten()<<endl;
            cout<<"Ma so sinh vien: "<<i.get_ID()<<endl;
            cout<<"Tuoi "<<i.get_tuoi()<<endl;
            switch (i.get_gioitinh())
            {
            case 0:
                cout<<"Gioi tinh nu"<<endl;
                break;
            case 1:
                cout<<"Gioi tinh nam"<<endl;
                break;
            default:
                break;
            }
            cout<<"Diem toan: "<<i.get_diemtoan()<<endl;
            cout<<"Diem ly: "<<i.get_diemly()<<endl;
            cout<<"Diem hoa: "<<i.get_diemhoa()<<endl;
            cout<<"Diem trung binh: "<<i.get_diemtb()<<endl;
            switch (i.get_hocluc())
            {
            case 0:
                cout<<"Hoc luc gioi"<<endl;
                break;
            case 1:
                cout<<"Hoc luc kha"<<endl;
                break;
            case 2:
                cout<<"Hoc luc trung binh"<<endl;
                break;
            case 3:
                cout<<"Hoc luc yeu"<<endl;        
                break;
            default:
                break;
            }   
        }
    
}

int main(int argc, char const *argv[])
{
    list<SinhVien> database;
    int input;
    while (1)
    {
        cout<<"Chuong trinh tao danh sach sinh vien"<<endl;
        cout<<"Nhap 0 de ket thuc chuong trinh"<<endl;
        cout<<"Nhap 1 de  them sinh vien"<<endl;
        cout<<"Nhap 2 de  cap nhat thong tin sinh vien theo ID"<<endl;
        cout<<"Nhap 3 de xoa sinh vien theo ID"<<endl;
        cout<<"Nhap 4 de tim kiem sinh vien theo ten"<<endl;  
        cout<<"Nhap 5 de sap xep sinh vien theo diem trung binh"<<endl;  
        cout<<"Nhap 6 de sap xep sinh vien theo ten"<<endl;                
        cout<<"Nhap 7 de hien thi danh sach sinh vien"<<endl;
        cout<<"Nhap input: "<<endl;
        cin>>input;
        if (input == 0)
        {
            break;
        } else if (input == 1)
            {
                addsinhvien(database);
            } else if (input == 2)
            {
                update(database);
            } else if (input == 3)
            {
                deletesinhvien(database);
            } else if (input == 4)
            {
                namesearching(database);
            } else if (input == 5)
            {
                sort_diemtb(database);
            } else if (input == 6)
            {
                sort_ten(database);
            } else if (input == 7)
            {
                print_sv(database);
            }
    }
    
    return 0;
}
