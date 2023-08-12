#ifndef TABLE_HPP
#define TABLE_HPP

/*
* File: table.hpp
* Author: Thai Thang
* Date: 11/8/2023
* Description: This is a file include everything in preprocessor for table.cpp
*/

#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\order.hpp"

class Table{
    private:
    list<Order> ORDER_DISH;
    bool STATUS;
    public:
    Table();
    void set_status(bool status);
    bool get_status();
    void set_order(Order new_dish);
    list<Order> &get_order();
    bool delete_order(int ID);
    void clear_order();
};

void pay_bill(Table &table);

void print_table_status(vector<Table> &table);

int choose_table(vector<Table> &table);

void resize(vector<Table> &table, int num);

#endif