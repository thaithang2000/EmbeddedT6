/*
* File: table.hpp
* Author: Thai Thang
* Date: 12/08/2023
* Description: This is a file include method of class table and function for class table
*/

#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\table.hpp"

/*
* Conductor: Table
* Description: create a object Table with property STATUS
* Output:
*   Table - a object
*/

Table::Table(){
    STATUS = true;
}

/*
* Method: set_status
* Description: set a status for the table
* Input:
*  status - a bool value - status of the table
*/

void Table::set_status(bool status){
    STATUS = status;
}

/*
* Method: get_status
* Description: get a status of the table
* Output:
*  STATUS - a bool value - status of the table
*/

bool Table::get_status(){
    return STATUS;
}

/*
* Method: set_order
* Description: set a order for the table
* Input:
*  new_order - an Order class - order need to set
*/

void Table::set_order(Order new_order){
    ORDER_DISH.push_front(new_order);
    STATUS = false;
}

/*
* Method: get_order
* Description: get order of the table
* Output:
*  ORDER_DISH - a list with type is Order - order of the table
*/

list<Order>& Table::get_order(){
    return ORDER_DISH;
}

/*
* Method: delete_order
* Description: delete order of the table by enter the ID
* Input:
*  int ID - an interger value -ID of the dish
* Output:
*  count - a bool value - 1 if have that ID and delete the order. 0 if not have that ID
*/

bool Table::delete_order(int ID){
    bool count = 0;
    for (auto it = ORDER_DISH.begin(); it != ORDER_DISH.end(); it++)
    {
        if (it->get_ID() == ID)
        {
            ORDER_DISH.erase(it);
            count = 1;
            return count;
        }
    }
    return count;

}

/*
* Method: clear_order
* Description: clear all the order of table
*/

void Table::clear_order(){
    ORDER_DISH.clear();
}

/*
* Function: pay_bill
* Description: pay bill for the table
* Input:
*  table - an object with class is table -a table
*/

void pay_bill(Table &table){
    table.set_status(true);
    table.clear_order();
}

/*
* Function: print_table_status
* Description: print all the table in restaurant and its status
* Input:
*  table - a vector with type is class Table - a vector with type is class Table
*/

void print_table_status(vector<Table> &table){
        system("CLS");
        cout<<"------------------------------TABLE'STATUS------------------------------"<<endl;
        cout<<"No.      ";
        for (int i = 1; i <= table.size(); i++)
        {
            cout<<" "<<i;
        }
        cout<<endl;
    
        cout<<"Status.  ";
        for (int i = 1; i <= table.size(); i++)
        {
            if(table.at(i - 1).get_status()) 
            {
                cout<<" O";
            } else cout<<" X";
        
        }
        cout<<endl<<"O: available"<<" X: unavailable"<<endl;


}

/*
* Function: choose_table
* Description: choose the table in restaurant
* Input:
*  table - a vector with type is class Table - a vector with type is class Table
* Output:
*  i-1 - an interger value - a position of table
*/

int choose_table(vector <Table> &table){
    int i;
    do
    {
        cout<<"ENTER THE NUMBER OF TABLE YOU WANT TO CHOOSE: "<<endl;
        cin>>i;
    } while (i <= 0 && i >= table.size());
    return (i-1);
}

/*
* Function: resize
* Description: resize the table in restaurant
* Input:
*  table - a vector with type is class Table - a vector with type is class Table
*  num - an interger value - number of the table
*/

void resize(vector<Table> &table, int num){

    table.resize(num);
}