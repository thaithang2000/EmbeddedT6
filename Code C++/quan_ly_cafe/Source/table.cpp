#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\table.hpp"

Table::Table(){
    STATUS = true;
}

void Table::set_status(bool status){
    STATUS = status;
}

bool Table::get_status(){
    return STATUS;
}

void Table::set_order(Order new_order){
    ORDER_DISH.push_front(new_order);
    STATUS = false;
}

list<Order>& Table::get_order(){
    return ORDER_DISH;
}

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

void Table::clear_order(){
    ORDER_DISH.clear();
}

void pay_bill(Table &table){
    table.set_status(true);
    table.clear_order();
}

void print_table_status(vector<Table> &table, int number_table){
        system("CLS");
        cout<<"------------------------------TABLE'STATUS------------------------------"<<endl;
        cout<<"No.      ";
        for (int i = 1; i <= number_table; i++)
        {
            cout<<" "<<i;
        }
        cout<<endl;
    
        cout<<"Status.  ";
        for (int i = 1; i <= number_table; i++)
        {
            if(table.at(i - 1).get_status()) 
            {
                cout<<" O";
            } else cout<<" X";
        
        }
        cout<<endl<<"O: available"<<" X: unavailable"<<endl;


}


int choose_table(int number_table){
    int i;
    do
    {
        cout<<"ENTER THE NUMBER OF TABLE YOU WANT TO CHOOSE: "<<endl;
        cin>>i;
    } while (i <= 0 && i > number_table);
    return (i-1);
}