#include <iostream>
#include <string>
#include <list>
#include <cassert>


using namespace std;

class Dish{
    protected:
    int ID;
    string NAME;
    double PRICE;
    public:
    Dish(string name, double price);
    void set_name(string name);
    void set_price(double price);
    int get_ID();
    string get_name();
    double get_price();
};

Dish::Dish(string name, double price){
    static int id = 100;
    ID = id;
    id++;
    NAME = name;
    PRICE = price;
    assert((price >= 0) && "gia mon khong hop le");
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

class Manager{
    private:
    int tables;
    protected:
    list<Dish> data;
    public:
    void add_dish();
    void update_dish();
    void delete_dish();
    list<Dish>get_menu();
    void display_menu();
    void set_tables(int number);
    int get_tables();
};

void Manager::add_dish(){
    int loop;
    do
    {
        string name;
        double price;
        cout<<"Enter the dish's name: "<<endl;
        cin>>name;
        cout<<"Enter the dish's price: "<<endl;
        cin>>price;
        Dish temp(name, price);
        data.push_back(temp);
        cout<<"Information of new dish"<<endl;
        cout<<" ID: "<<temp.get_ID()<<" Name: "<<temp.get_name()<<" Price "<<temp.get_price()<<endl;
        cout<<"Press 1 to continue add new dish. Press 0 to go back"<<endl;
        cin>>loop;
        while (loop != 0 && loop != 1){
            cout<<"Error. Press 1 to continue add new dish. Press 0 to go back"<<endl;
            cin>>loop;
        }

    } while (loop == 1);
    
}

void Manager::update_dish(){
    int id, temp = 0;
    display_menu();
    cout<<"ENTER ID: "<<endl;
    cin>>id;
    for (auto i : data)
    {
        if (id == i.get_ID())
        {
            temp = 1;
            string new_name;
            double new_price;
            int loop;
            do
            {
                cout<<"------------------------------------------------------------------"<<endl;  
                cout<<" ID: "<<i.get_ID()<<" NAME: "<<i.get_name()<<" PRICE: "<<i.get_price()<<endl;
                cout<<"------------------------------------------------------------------"<<endl;       
                cout<<"Press 1 to change name. Press 2 to change price. Press 0 to go back"<<endl;
                cin>>loop;
                switch (loop)
                {
                case 0:
                    break;
                case 1:
                    cout<<"Enter new name: "<<endl;
                    cin>>new_name;
                    i.set_name(new_name);
                    cout<<"Update completed "<<endl;    
                    break;
                case 2:
                    cout<<"Enter new price: "<<endl;
                    cin>>new_price;
                    i.set_price(new_price); 
                    cout<<"Update completed "<<endl;
                    break;                   
                default:
                    cout<<"Invalid choice. Try again"<<endl;
                    break;
                }

            } while (loop == 1 || loop == 2);
            
        }
        
    }

    if (temp == 0)
    {
        cout<<"Do not have that ID"<<endl;
    }

}

void Manager::delete_dish(){
    int id, temp = 0;
    cout<<"ENTER ID: "<<endl;
    cin>>id;
    for (auto it=data.begin();it != data.end(); it++)
    {
        if (id == it->get_ID())
        {
            temp = 1;
            data.erase(it);  
            cout<<"Delete completed"<<endl;
            break;
        }
        
    }

    if (temp == 0)
    {
        cout<<"Do not have that ID"<<endl;   
    }
    


}

list<Dish>Manager::get_menu(){
    return data;
}

void Manager::display_menu(){
    cout<<"---------------------MENU---------------------"<<endl;
    for (auto i : data)
    {
        cout<<" ID: "<<i.get_ID()<<" NAME: "<<i.get_name()<<" PRICE "<<i.get_price()<<endl;
    }
    
}

void Manager::set_tables(int number){
    tables = number;
}

int Manager::get_tables(){
    return tables;
}

int main(int argc, char const *argv[])
{
    Manager user1;

    int input, option;

    do
    {
        cout<<"--------------------------------MENU-----------------------------"<<endl;
        cout<<"MANAGER PRESS 1. EMPLOYEE PRESS 2. PRESS 0 TO EXIT"<<endl;
        cin>>input;
        switch (input)
        {
        case 0:
            break;
        case 1:
            do
            {
                cout<<"--------------------------------MANAGER-----------------------------"<<endl;
                cout<<"PRESS 1 TO SET TABLE. PRESS 2 TO ADD NEW DISH. PRESS 3 TO UPDATE THE DISH. PRESS 4 TO DELETE THE DISH. PRESS 5 TO SHOW MENU. PRESS 0 TO GO BACK"<<endl;
                cin>>option;
                switch (option)
                {
                case 0:
                    break;
                case 1:
                    int num;
                    cout<<"Enter number of tables: "<<endl;
                    cin>>num;
                    while (num <= 0)
                    {
                        cout<<"Enter number of tables: "<<endl;
                        cin>>num;
                    }
                    
                    user1.set_tables(num);
                    cout<<"Number of tables: "<<user1.get_tables()<<endl;

                    break;
                case 2:
                    user1.add_dish();
                    break;
                case 3:
                    user1.update_dish();
                    break;
                case 4:
                    user1.delete_dish();
                    break;
                case 5:
                    user1.display_menu();
                    break;
                default:
                    break;
                }
            } while (option != 0);
            
        default:
            break;
        }

    } while (input != 0);
    
    
    return 0;
}
