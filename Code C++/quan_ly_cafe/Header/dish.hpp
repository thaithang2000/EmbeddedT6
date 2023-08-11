#ifndef DISH_HPP
#define DISH_HPP

/*
* File: dish.hpp
* Author: Thai Thang
* Date: 11/8/2023
* Description: This is a file include everything in preprocessor for dish.cpp
*/

#include <iostream>
#include <string>
#include <list>
#include<vector>
#include <cassert>


using namespace std;

typedef enum{
    GO_BACK = 0,
    SET_TABLE = 1,
    ADD_DISH = 2,
    EDIT_DISH = 3,
    DELETE_DISH = 4,
    SHOW_DISH = 5

} Manager_Func;

typedef enum{
    ADD_ORDER = 1,
    EDIT_ORDER = 2,
    DELETE_ORDER = 3,
    SHOW_ORDER = 4,
    PAY = 5
} Staff_Func;


class Dish{
    protected:
    int ID;
    string NAME;
    double PRICE;
    public:
    Dish(string name, double price);
    Dish();
    void set_name(string name);
    void set_price(double price);
    int get_ID();
    string get_name();
    double get_price();
};

void add_dish(list<Dish> &database);

void edit_dish(list<Dish> &database);

void delete_dish(list<Dish> &database);

void print_menu(list<Dish> &database);


#endif // DISH_HPP