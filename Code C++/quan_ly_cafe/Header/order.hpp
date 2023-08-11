#ifndef ORDER_HPP
#define ORDER_HPP

/*
* File: order.hpp
* Author: Thai Thang
* Date: 11/8/2023
* Description: This is a file include everything in preprocessor for order.cpp
*/

#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\dish.hpp"

class Order : public Dish{
    private:
    unsigned int NUMBER_DISH;
    public:
    Order(unsigned int number_dish);
    void set_number_dish(unsigned int num);
    void set_id(int id);
    unsigned int get_number_dish();
};

void add_order(list<Order> &database_order,list<Dish> &database);

void edit_order(list<Order> &database_order);

void delete_order(list<Order> &database_order);

void print_order(list<Order> &database_order);

void print_bill(list<Order> &database_order);




#endif // ORDER_HPP