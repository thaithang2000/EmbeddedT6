#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    public:
    string Ten;
    int Tuoi;
    string GioiTinh;
    int ID;
    int *ptr;
    int var;
    static int static_var;
    DoiTuong(string ten = "Thang", int tuoi = 23, string gioitinh = "Nam") // dung de tao ra gia tri mac dinh khi khong nhap input parameter
    {
        static int id = 1;
        ID = id;
        ptr = &id;
        id++;

        Ten = ten;
        Tuoi = tuoi;
        GioiTinh = gioitinh;
    }
    ~DoiTuong()  // khi thoat ra khoi ham thi se vao day gan gia tri ptr = 1
    {
        *ptr = 1;
    }
    void hienthi(){
        cout<<"Ten: "<<Ten<<endl;
        cout<<"Tuoi: "<<Tuoi<<endl;
        cout<<"Gioi tinh: "<<GioiTinh<<endl;
        cout<<"MSSV: "<<ID<<endl;
    }

};

void test1(){
    DoiTuong nv("Long",10,"Nam");
    nv.hienthi();
}

void test2(){
    DoiTuong nv("Ngoc",12,"Nu");
    nv.hienthi();
}
 
int DoiTuong::static_var;
int main(int argc, char const *argv[])
{
    DoiTuong nv;
    nv.hienthi();

    DoiTuong nv1("Hoang",15,"Nam");
    nv1.hienthi();

    test1();
    test2();

    printf("Dia chi var: %p\n",&nv.var);
    printf("Dia chi var: %p\n",&nv1.var);
    printf("Dia chi static var: %p\n",&nv.static_var);
    printf("Dia chi static var: %p\n",&nv1.static_var);
    return 0;
}
