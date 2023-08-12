/*
* File: dish.hpp
* Author: Thai Thang
* Date: 12/08/2023
* Description: This is a file include method of class dish and function for class dish
*/

#include"C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\dish.hpp"


/*
* Conductor: Dish
* Description: create a class Dish with 3 property name, price, id (id is auto increase)
* Input:
*   name -  a string value - name of the dish
*   price -  a double value - price of the dish 
* Output:
*   Dish - a class
*/

Dish::Dish(string name, double price){
    static int id = 100;
    ID = id;
    id++;
    NAME = name;
    PRICE = price;
    assert((price >= 0) && "gia mon khong hop le");
}

/*
* Conductor: Dish
* Description: create a class Dish without input parameter

* Output:
*   Dish - a class with name is CAFE and price is 10.5
*/

Dish::Dish(){
    NAME = "CAFE";
    PRICE = 10.5;
}


/*
* Method: set_name
* Description: set name for the object
* Input:
*   name -  a string value - name of the dish
*/

void Dish::set_name(string name){
    NAME = name;
}

/*
* Method: set_price
* Description: set price for the object
* Input:
*   price -  a double value - price of the dish
*/

void Dish::set_price(double price){
    PRICE = price;
}

/*
* Method: get_ID
* Description: get ID of the object
* Output:
*   ID- an interger value - ID of the object
*/

int Dish::get_ID(){
    return ID;
}

/*
* Method: get_name
* Description: get name of the object
* Input:
*   NAME -  a string value - name of the dish
*/

string Dish::get_name(){
    return NAME;
}

/*
* Method: get_price
* Description: get price of the object
* Input:
*   PRICE -  a double value - price of the dish
*/

double Dish::get_price(){
    return PRICE;
}

/*
* Function: add_dish
* Description: add dish to the database
* Input:
*   database -  a list - database of dish
*/

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

/*
* Function: edit_dish
* Description: edit dish to the database by enter the dish'id
* Input:
*   database -  a list - database of dish
*/

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

/*
* Function: delete_dish
* Description: delete dish to the database by enter the dish'id
* Input:
*   database -  a list - database of dish
*/

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

/*
* Function: print_menu
* Description: print all the dishes
* Input:
*   database -  a list - database of dish
*/

void print_menu(list<Dish> &database){
    cout<<"--------------------------MENU--------------------------"<<endl;
    for (auto it = database.begin(); it != database.end(); it++)
    {
        cout<<"ID: "<<it->get_ID()<<"   NAME: "<<it->get_name()<<"  PRICE: "<<it->get_price()<<endl;
    }
    
}