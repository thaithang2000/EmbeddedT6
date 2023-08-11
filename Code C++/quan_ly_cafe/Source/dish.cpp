#include"C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\dish.hpp"

Dish::Dish(string name, double price){
    static int id = 100;
    ID = id;
    id++;
    NAME = name;
    PRICE = price;
    assert((price >= 0) && "gia mon khong hop le");
}

Dish::Dish(){
    NAME = "CAFE";
    PRICE = 10.5;
}

void Dish::set_name(string name){
    NAME = name;
}

void Dish::set_price(double price){
    PRICE = price;
}

int Dish::get_ID(){
    return ID;
}

string Dish::get_name(){
    return NAME;
}

double Dish::get_price(){
    return PRICE;
}



void add_dish(list<Dish> &database){
    string name;
    double price;
    cout<<"Name of the dish: "<<endl;
    cin>>name;
    cout<<"Price of the dish: "<<endl;
    cin>>price;
    Dish food(name,price);
    database.push_back(food);    
}

void edit_dish(list<Dish> &database){
    int id, count;
    double price;
    cout<<"Enter id of the dish: "<<endl;
    cin>>id;
    for (auto it = database.begin(); it != database.end(); it++)
    {
        if (it->get_ID() == id)
        {
            count = 1;
            cout<<"Price of the dish: "<<endl;
            cin>>price;
            it->set_price(price);
            break;
        }
        
    }
    if (count != 1)
    {
        cout<<"Not have that ID"<<endl;
    }
    
}

void delete_dish(list<Dish> &database){
    int id, count;
    cout<<"Enter id of the dish: "<<endl;
    cin>>id;
    for (auto it = database.begin(); it != database.end(); it++)
    {
        if (it->get_ID() == id)
        {
            count = 1;
            database.erase(it);
            break;
        }
        
    }
    if (count != 1)
    {
        cout<<"Not have that ID"<<endl;
    }
    
}

void print_menu(list<Dish> &database){
    cout<<"--------------------------MENU--------------------------"<<endl;
    for (auto it = database.begin(); it != database.end(); it++)
    {
        cout<<"ID: "<<it->get_ID()<<"   NAME: "<<it->get_name()<<"  PRICE: "<<it->get_price()<<endl;
    }
    
}