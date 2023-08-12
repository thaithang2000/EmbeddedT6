/*
* File: fuction.hpp
* Author: Thai Thang
* Date: 12/08/2023
* Description: This is a file include the function for managing the cafeteria
*/

#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\function.hpp"

/*
* Function: manager
* Description: all function for the manager
* Input:
*   menu -  a list with type is class Dish - database of dish
*   table - a vector with type is class Table - database of table
*/

void manager(list<Dish> &menu, vector <Table> &table){
    bool manager_func = true;
    int number_of_table;
    while (manager_func)
    {
        int chose_manager_func;
        do
        {
            system("CLS");
            cout<<"PRESS 1 TO SET NUMBER OF TABLES"<<endl;
            cout<<"PRESS 2 TO ADD NEW DISH"<<endl;
            cout<<"PRESS 3 TO EDIT THE DISH"<<endl;
            cout<<"PRESS 4 TO DELETE THE DISH"<<endl;
            cout<<"PRESS 5 TO SHOW THE MENU"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cout<<"CHOOSE THE FUNCTION: "<<endl;
            cin>>chose_manager_func;                    
        } while (chose_manager_func < 0 && chose_manager_func > 5);
        
        switch (chose_manager_func)
        {
        case GO_BACK:
            manager_func = false;
            break;

        case SET_TABLE:
            do
            {
                cout<<"ENTER THE NUMBER OF TABLE: "<<endl;
                cin>>number_of_table;
            } while (number_of_table <= 0);

            resize(table,number_of_table);
            break;

        case ADD_DISH:
            {
                bool again = true;
                int temp;
                while (again)
                {
                    system("CLS");
                    add_dish(menu);
                    do
                    {
                        cout<<"PRESS 1 TO ADD ANOTHER DISH: "<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>temp;
                    } while (temp != 0 && temp != 1);
                    
                    if (temp == 0)
                    {
                        again = false;
                    }
                }
            }
            break;

        case EDIT_DISH:
            {
                bool again = true;
                int temp;
                while (again)
                {
                    system("CLS");
                    print_menu(menu);
                    edit_dish(menu);
                    do
                    {
                        cout<<"PRESS 1 TO EDIT ANOTHER DISH: "<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>temp;
                    } while (temp != 0 && temp != 1);
                    
                    if (temp == 0)
                    {
                        again = false;
                    }
                }
            }
            
            break;
        
        case DELETE_DISH:
            {
                bool again = true;
                int temp;
                while (again)
                {
                    system("CLS");
                    print_menu(menu);
                    delete_dish(menu);
                    do
                    {
                        cout<<"PRESS 1 TO DELETE ANOTHER DISH: "<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>temp;
                    } while (temp != 0 && temp != 1);
                    
                    if (temp == 0)
                    {
                        again = false;
                    }
                }
            }
    
            break;

        case SHOW_DISH:
            {
                int temp;
                do
                {
                    system("CLS");
                    print_menu(menu);
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>> temp;
                } while (temp != 0);
            }
            
            break;

        default:
            break;            

        }   
    }
}

/*
* Function: staff
* Description: all function for the staff
* Input:
*   menu -  a list with type is class Dish - database of dish
*   table - a vector with type is class Table - database of table
*/

void staff(list<Dish> &menu, vector <Table> &table){
    bool chose_table = true;
    bool staff_func = true;
    int chose;
    int number_of_table;
    while (chose_table)
    {
        int chose_func = 0;
        print_table_status(table);

        do
        {
            cout<<"PRESS 1 TO CHOOSE TABLE"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>chose_func;
        } while (chose_func != 0 && chose_func != 1);

        switch (chose_func)
        {
        case GO_BACK:
            chose_table = false;
            staff_func = false;
            break;

        case ADD_ORDER:
            chose = choose_table(table);
            staff_func = true;
        default:
            break;
        }

        while (staff_func)
        {
            int chose_staff_func;

            do
            {
                system("CLS");
                cout<<"PRESS 1 ADD ORDER FOR TABLE"<<endl;
                cout<<"PRESS 2 EDIT ORDER FOR TABLE"<<endl;
                cout<<"PRESS 3 TO DELETE ORDER FOR TABLE"<<endl;
                cout<<"PRESS 4 TO PRINT THE ORDER"<<endl;
                cout<<"PRESS 5 TO PAY THE BILL"<<endl;
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cout<<"CHOOSE THE FUNCTION: "<<endl;
                cin>>chose_staff_func;
            } while (chose_staff_func < 0 && chose_staff_func > 5);

            switch (chose_staff_func)
            {
            case GO_BACK:
                staff_func = false;
                break;

            case ADD_ORDER:
                {
                    bool again = true;
                    int temp;
                    while (again)
                    {
                        system("CLS");
                        print_menu(menu);
                        add_order(table[chose].get_order(),menu);
                        table.at(chose).set_status(false) ;
                        do
                        {
                            cout<<"PRESS 1 TO ADD ANOTHER ORDER"<<endl;
                            cout<<"PRESS 0 TO GO BACK"<<endl;
                            cin>>temp;
                        } while (temp != 0 && temp != 1);

                        if (temp == 0)
                        {
                            again = false;
                        }
                    }
                }
                
                break; 
            
            case EDIT_ORDER:
                {
                    bool again = true;
                    int temp;

                    while (again)
                    {
                        system("CLS");
                        print_order(table[chose].get_order());
                        edit_order(table[chose].get_order());
                        
                        do
                        {
                            cout<<"PRESS 1 TO EDIT ANOTHER ORDER"<<endl;
                            cout<<"PRESS 0 TO GO BACK"<<endl;
                            cin>>temp;
                        } while (temp != 0 && temp != 1);

                        if (temp == 0)
                        {
                            again = false;
                        } 
                    }
                }
                
                break;

            case DELETE_ORDER:
                {
                    bool again = true;
                    int temp;
                    while (again)
                    {
                        system("CLS");
                        print_order(table[chose].get_order());
                        delete_order(table.at(chose).get_order());
                        do
                        {
                            cout<<"PRESS 1 TO DELETE ANOTHER ORDER"<<endl;
                            cout<<"PRESS 0 TO GO BACK"<<endl;
                            cin>>temp;
                        } while (temp != 0 && temp != 1);
                        
                        if (temp == 0)
                        {
                            again = false;
                        }
                    }
                }
                
                break;

            case SHOW_ORDER:
                {
                    bool again = true;
                    int temp = 0;
                    while (again)
                    {
                        system("CLs");
                        do
                        {
                            print_order(table.at(chose).get_order());
                            cout<<"PRESS 0 TO GO BACK"<<endl;
                            cin>>temp;
                        } while (temp != 0);
                        
                        if (temp == 0)
                        {
                            again = false;
                        }
                        
                    }
                }
                
                break;
            
            case PAY:
                {
                    bool again = true;
                int temp = 0;
                while (again)
                {
                    system("CLs");
                    do
                    {
                        print_bill(table.at(chose).get_order());
                        cout<<"PRESS 1 TO PAY THE BILL"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>temp;
                    } while (temp != 0 && temp != 1);
                    
                    if (temp == 0)
                    {
                        again = false;
                    }

                    if (temp == 1)
                    {
                        pay_bill(table[chose]);
                        again = false;
                    }
                }
                }
                
                break;
            
            default:
                break;
            }
        }
    }
}