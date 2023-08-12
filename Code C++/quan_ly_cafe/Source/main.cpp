
#include "C:\Users\thang\Desktop\embedded\Code C++\quan_ly_cafe\Header\function.hpp"

using namespace std;

int main(int argc, char const *argv[])
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
            manager(menu,table);
            
        }
        
        if (chose_position == 2)
        {

            staff(menu,table);
            
        }
        
    }
    
    return 0;
}