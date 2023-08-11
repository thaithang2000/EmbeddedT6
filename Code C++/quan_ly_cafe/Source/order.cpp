#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\order.hpp"

Order::Order(unsigned int number_dish){
    NUMBER_DISH = number_dish;
}

void Order::set_number_dish(unsigned int num){
    NUMBER_DISH = num;
}

void Order::set_id(int id){
    ID = id;
}

unsigned int Order::get_number_dish(){
    return NUMBER_DISH;
}

void add_order(list<Order> &database_order,list<Dish> &database){
    int id, count;
    cout<<"Enter ID of the dish"<<endl;
    cin>>id;
    for (auto i = database.begin(); i != database.end(); i++)
    {
        if (i->get_ID() == id)
        {
            count = 1;
            unsigned int num;
            cout<<"Enter number of dish: "<<endl;
            cin>>num;
            Order dish(num);
            dish.set_name(i->get_name());
            dish.set_price(i->get_price());
            dish.set_id(i->get_ID());
            database_order.push_front(dish);
            cout<<"Add order completed"<<endl;
            break;
        }
        
    }
    if (count != 1)
    {
        cout<<"Not have that ID"<<endl;
    }
    
}

void edit_order(list<Order> &database_order){
    int ID, num;
    int count = 0;
    cout<<"Enter ID of the dish: "<<endl;
    cin>>ID;
    for (auto i = database_order.begin(); i != database_order.end(); i++)
    {
        if (i->get_ID() == ID)
    {
        count = 1;
        cout<<"ID: "<<i->get_ID()<<" NAME: "<<i->get_name()<<" PRICE: "<<i->get_price()<<" QUANTITY: "<<i->get_number_dish()<<endl;
        cout<<"ENTER NUMBER OF DISH: "<<endl;
        cin>>num;
        i->set_number_dish(num);
        cout<<"Edit completed"<<endl;
        break;
    }

    }
    
    if (count != 1)
    {
        cout<<"Not have that ID"<<endl;
    }
    
}

void delete_order(list<Order> &database_order){
    int ID;
    int count = 0;
    cout<<"Enter ID of the dish: "<<endl;
    cin>>ID;
    for (auto i = database_order.begin(); i != database_order.end(); i++)
    {
        if (i->get_ID() == ID)
    {
        count = 1;
        database_order.erase(i);
        cout<<"Delete order completed"<<endl;
        break;
    }

    }
    
    if (count != 1)
    {
        cout<<"Not have that ID"<<endl;
    }
    
}

void print_order(list<Order> &database_order){
    int count = 0;
    for (auto it = database_order.begin(); it != database_order.end(); it++)
    {
        count++;
        cout<<"------------------------------ORDER--------------------------"<<endl;
        cout<<"No."<<count<<" ID: "<<(it)->get_ID()<<" NAME: "<<(it)->get_name()<<" PRICE: "<<(it)->get_price()<<" QUANTITY: "<<(it)->get_number_dish()<<endl;
    }
    
}

void print_bill(list<Order> &database_order){
    double total = 0;
    print_order(database_order);

    for (auto it = database_order.begin(); it != database_order.end(); it++)
    {
        total = total + (it->get_number_dish() * it->get_price());
    }
    

    cout<<"------------------------------------------------"<<endl;
    cout<<"Total: "<<total<<endl;
    cout<<"------------------------------------------------"<<endl;    
}