#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    private:
        int test1;
    protected:  // tuong tu private object chi tro toi duoc pham vi truy cap public
        string TEN;  // pham vi truy cap private va protected khong tro toi duoc
        int NAM_SINH;    // protected class con van co the su dung duoc con private thi khong 
        string DIA_CHI;
        int tinhtuoi(int nam_sinh); //tinh truu tuong: cac property(bien),cac method(chuong trinh con) dung de tinh toan phai de o private 
    public:                         //hoac protected vi nguoi dung khong can quan tam, ho chi can biet ket qua cuoi cung
        void themthongtin(string ten, int nam_sinh, string dia_chi);
        void hienthi();
        int test_protected;
        int test_private;
};

void DoiTuong::themthongtin(string ten, int nam_sinh, string dia_chi){
    TEN = ten;
    NAM_SINH = nam_sinh;
    DIA_CHI = dia_chi;
}

int DoiTuong::tinhtuoi(int nam_sinh){
    return 2023-nam_sinh;
}

void DoiTuong::hienthi(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Nam sinh: "<<NAM_SINH<<endl;
    cout<<"Tuoi: "<<tinhtuoi(NAM_SINH)<<endl;
    cout<<"Dia chi: "<<DIA_CHI<<endl;
}
//ke thua thuoc tinh cua class cha (DoiTuong): neu ke thua kieu public thi class cha la pham nao thi class con la pham vi do 
//vd: cac member TEN,NAM_SINH o DoiTuong la protected qua SinhVien cung la protected va themthongtin() la public qua SinhVien cung la public
class SinhVien : public DoiTuong{ 
    private:  //tinh dong goi: cac property khai bao phai o pham vi private hoac protected vi khong the cho nguoi dung khai bao truc tiep vao ma phai thong qua method
        int MSSV;
    public:
        SinhVien();
        void hienthi(); //overwrite ghi de thuoc tinh cua class cha (DoiTuong)
};

SinhVien::SinhVien(){
    static int mssv = 1000;
    MSSV = mssv;
    mssv++;
}

void SinhVien ::hienthi(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<tinhtuoi(NAM_SINH)<<endl;
    cout<<"Dia chi: "<<DIA_CHI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;
}



//ke thua thuoc tinh cua class cha (DoiTuong): neu ke thua kieu protected thi class cha la public nao thi class con la protected 
//vd: cac member TEN,NAM_SINH o DoiTuong la protected qua Protected_SinhVien cung la protected 
//va themthongtin() la public qua Protected_SinhVien  la protected
class Protected_SinhVien : protected DoiTuong{ 

};

class Hoc_sinh : public Protected_SinhVien{
    public:
    void get_protected_test(int value);
};

void Hoc_sinh::get_protected_test(int value){
    test_protected = value;
    cout<<"Gia tri test: "<<test_protected<<endl;
}


//ke thua thuoc tinh cua class cha (DoiTuong): neu ke thua kieu private thi class cha la public nao thi class con la private 
//vd: cac member TEN,NAM_SINH o DoiTuong la protected qua Private_SinhVien  la private 
//va themthongtin() la public qua Private_SinhVien  la private
class Private_SinhVien : private DoiTuong{ 
    public:
    Private_SinhVien();
};
//ta khong the goi test_private truc tiep nhu tren ma phai thong qua method
class Private_Hoc_sinh : public Private_SinhVien{
};

Private_SinhVien::Private_SinhVien(){
    test_private = 100;
    themthongtin("Thang",2000,"Nam");
    hienthi();
    cout<<"Test: "<<test_private<<endl;
}

int main(int argc, char const *argv[])
{
    DoiTuong dt;
    dt.themthongtin("Hoang",1997,"HCM");
    dt.hienthi();

    SinhVien sv;
    sv.themthongtin("Ly",2000,"HN");
    sv.hienthi();

    Hoc_sinh hs;
    hs.get_protected_test(10);

    Private_SinhVien sv1;
    return 0;
}
