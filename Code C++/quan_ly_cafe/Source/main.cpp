#include <iostream>
#include <string>
#include <list>
#include<vector>
#include <cassert>
#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\table.hpp"

using namespace std;

int main()
{
    list<Dish> menu;
    int number_of_table = 1;
    vector <Table> table(number_of_table);
    bool program = true;
    while (program)
    {
        int chose_position;
        do
        {
            system("CLS");
            cout<<"PRESS 1 TO ENTER MANAGER PROGRAM"<<endl;
            cout<<"PRESS 2 TO ENTER STAFF PROGRAM"<<endl;
            cout<<"PRESS 0 TO EXIT"<<endl;
            cout<<"ENTER NUMBER: "<<endl;
            cin>>chose_position;

        } while (chose_position != 0 && chose_position != 1 && chose_position != 2);
        
        if (chose_position == 0)
        {
            program = false;
        }

        if (chose_position == 1)
        {
            bool manager_func = true;
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
                
                if (chose_manager_func == GO_BACK)
                {
                    manager_func = false;
                }
                
                if (chose_manager_func == SET_TABLE)
                {
                    do
                    {
                        cout<<"ENTER THE NUMBER OF TABLE: "<<endl;
                        cin>>number_of_table;
                    } while (number_of_table < 0);

                    table.resize(number_of_table);
                }
                
                if (chose_manager_func == ADD_DISH)
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

                if (chose_manager_func == EDIT_DISH)
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
                
                if (chose_manager_func == DELETE_DISH)
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

                if (chose_manager_func == SHOW_DISH)
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

            }
            
        }
        
        if (chose_position == 2)
        {
            bool chose_table = true;
            bool staff_func = true;
            int chose;
            while (chose_table)
            {
                int chose_func = 0;
                print_table_status(table,number_of_table);

                do
                {
                    cout<<"PRESS 1 TO CHOOSE TABLE"<<endl;
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>chose_func;
                } while (chose_func != 0 && chose_func != 1);

                if (chose_func == GO_BACK)
                {
                    chose_table = false;
                    staff_func = false;
                }
                
                if (chose_func == ADD_ORDER)
                {
                    chose = choose_table(number_of_table);
                    staff_func = true;
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
                
                    if (chose_staff_func == GO_BACK)
                    {
                        staff_func = false;
                    }

                    if (chose_staff_func == ADD_ORDER)
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

                    if (chose_staff_func == EDIT_ORDER)
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

                    if (chose_staff_func == DELETE_ORDER)
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

                    if (chose_staff_func == SHOW_ORDER)
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
                    
                    if (chose_staff_func == PAY)
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
                
                
                
                
                }
            }
            
           

            
        }
        
        

    }
    
    return 0;
}