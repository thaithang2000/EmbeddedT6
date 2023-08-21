#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef struct
{
    int day;
    int month;
    int year; 
}typeDate;

typedef struct 
{
    int hour;
    int minute;
    int second;
}typdeTime;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef struct 
{
    typdeTime time;
    typeDate date;
    typeStatus status;
}bookingHistory;

typedef enum 
{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}job;


typedef struct
{
    typdeTime time;
    typeDate date;
}working_schedule;

typedef struct 
{
    int ID_Room;
    double Restaurant_Price;
    typeStatus Restaurant_Status;
    //double Pool_Price;
    //typeStatus Pool_Status;    
}typeService;

//--------------------------------------------------------------------//

class Room{
    private:
        int ID;
        bool cleaned;
        bool booked;
    public:
        Room(int number);
        int get_ID();
        bool isAvailable();
        void bookRoom();
        void checkIn();
        void checkOut();
};

Room::Room(int number){
    ID = number;
    cleaned = true;
    booked = false;
}

int Room::get_ID(){
    return ID;
}

bool Room::isAvailable(){
    return !booked && cleaned;
}

void Room::bookRoom(){
    booked = true;
}

void Room::checkIn(){
    booked = true;
    cleaned = false;
}

void Room::checkOut(){
    booked = false;
    cleaned = true;
}
//--------------------------------------------------------------------//
class Customer{
    private:
        int ID_ROOM;
        string NAME;
        string PHONE_NUMBER;
        string ADDRESS;
        vector<bookingHistory> booking_history;
    public:
        Customer(string name, string phone, string add, int id_room);
        void add_booking_history(bookingHistory booking_detail);
        void display_booking_history();

        string getname();
        void setname(string name);
        int getID();
        void setID(int id);
        string getphonenumber();
        void setphonenumber(string phone_number);
        string getaddress();
        void setaddress(string address);
};

Customer::Customer(string name, string phone, string add, int id_room){
    this->NAME = name;
    this->PHONE_NUMBER = phone;
    this->ADDRESS = add;
    this->ID_ROOM = id_room;
}

void Customer::add_booking_history(bookingHistory booking_detail){
    booking_history.push_back(booking_detail);
}

void Customer::display_booking_history(){
    cout<<"------------------BOOKING HISTORY------------------"<<endl;
    for (auto i = 0; i < booking_history.size(); i++)
    {
        printf("Date:\n Day: %s Month: %s Year: %s \n",booking_history[i].date.day,booking_history[i].date.month,booking_history[i].date.year);
        printf("Time:\n Hour: %d Minute: %d Second: %d \n",booking_history[i].time.hour,booking_history[i].time.minute,booking_history[i].time.second);
        printf("Status: %d 0 is OUT, 1 is IN \n",booking_history[i].status);
    }
    cout<<"\n";    
}

int Customer::getID(){
    return ID_ROOM;
}

void Customer::setID(int id){
    this->ID_ROOM = id;
}

string Customer::getname(){
    return NAME;
}

void Customer::setname(string name){
    this->NAME = name;
}

string Customer::getphonenumber(){
    return PHONE_NUMBER;
}

void Customer::setphonenumber(string phone_number){
    this->PHONE_NUMBER = phone_number;
}

string Customer::getaddress(){
    return ADDRESS;
}

void Customer::setaddress(string address){
    this->ADDRESS = address;
}

//--------------------------------------------------------------------//

class CustomerManager{
    private:
        vector<Customer> databaseCustomer;
    public:
        vector<Customer> &getdatabaseCustomer();
        void add_customer(Customer &customer);
        void delete_customer(vector<Room> &database_room, int id);
        void edit_customer_ID_Room(vector<Room> &database_room, int ID_Room_Current, int ID_Room_Change);
        void edit_customer_name(int ID_Room_Current, string new_name);
        void edit_customer_phone(int ID_Room_Current, string new_phone);
        void edit_customer_address(int ID_Room_Current, string new_address);
};

vector<Customer> &CustomerManager::getdatabaseCustomer(){
    return databaseCustomer;
}

void CustomerManager::add_customer(Customer &customer){
    databaseCustomer.push_back(customer);
}

void CustomerManager::delete_customer(vector<Room> &database_room, int id){
    for (auto i = 0; i < database_room.size(); i++)
    {
        if (database_room[i].get_ID() == id)
        {
            database_room[i].checkOut();
        }
        
    }
    
    
    for (auto i = 0; i < databaseCustomer.size(); i++)
    {
        if (databaseCustomer[i].getID() == id)
        {
            databaseCustomer.erase(databaseCustomer.begin()+i);
        }
        
    }
    
    
}



void CustomerManager::edit_customer_ID_Room(vector<Room> &database_room, int ID_Room_Current, int ID_Room_Change){
for (auto i = 0; i < database_room.size(); i++)
{
    if (database_room[i].get_ID() == ID_Room_Current) database_room[i].checkOut();
    if (database_room[i].get_ID() == ID_Room_Change) database_room[i].bookRoom();
}

for (auto i = 0; i < databaseCustomer.size(); i++)
{
    if (databaseCustomer[i].getID() == ID_Room_Current)
    {
        databaseCustomer[i].setID(ID_Room_Change);
    }
    
}
    
}

void CustomerManager::edit_customer_name(int ID_Room_Current, string new_name){
    for (auto i = 0; i < databaseCustomer.size(); i++)
    {
        if (databaseCustomer[i].getID() == ID_Room_Current)
        {
            databaseCustomer[i].setname(new_name);
        }
        
    }
}

void CustomerManager::edit_customer_phone(int ID_Room_Current, string new_phone){
    for (auto i = 0; i < databaseCustomer.size(); i++)
    {
        if (databaseCustomer[i].getID() == ID_Room_Current)
        {
            databaseCustomer[i].setphonenumber(new_phone);
        }
        
    }
}

void CustomerManager::edit_customer_address(int ID_Room_Current, string new_address){
    for (auto i = 0; i < databaseCustomer.size(); i++)
    {
        if (databaseCustomer[i].getID() == ID_Room_Current)
        {
            databaseCustomer[i].setaddress(new_address);
        }
        
    }
}

////////////////////////////////////////////////////////////////////////////////////////

class User{
    private:
        string USERNAME;
        string PASSWORD;
    public:
        User(string username, string password);
        string getUserName() {
            return USERNAME;
        };
        string getPassword() {
            return PASSWORD;
        }
        void setUserName(string inputUsername) {
            USERNAME = inputUsername;
        };
        void setPassword(string inputpassword) {
            PASSWORD = inputpassword;
        };
        bool check(string inputUsername, string inputPassword){
            bool checkSignUp = (inputUsername == USERNAME && inputPassword == PASSWORD);
            return checkSignUp;
        };

};

User::User(string username = "manager", string password = "admin"){
    this->USERNAME = username;
    this->PASSWORD = password;
}

//--------------------------------------------------------------------//

class Employee{
    private:
        int ID;
        string NAME;
        string PHONE_NUMBER;
        job JOB_POSITION;
        working_schedule SCHEDULE;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, job positionEmployee, working_schedule scheduleEmployee);
        void setname(string name);
        string getname();
        void set_phone_number(string number);
        string get_phone_number();
        void set_job_position(job pos);
        job get_job_position();
        void set_schedule(working_schedule schedule);
        working_schedule get_schedule();
        int get_ID();
};

Employee::Employee(string nameEmployee, string phoneNumberEmployee, job positionEmployee, working_schedule scheduleEmployee) {

    static int idEmployee = 100;
    this->ID = idEmployee;
    idEmployee++;

    this->NAME = nameEmployee;
    this->PHONE_NUMBER = phoneNumberEmployee;
    this->JOB_POSITION = positionEmployee;
    this->SCHEDULE = scheduleEmployee;

};

void Employee::setname(string name){
    this->NAME = name;
}

string Employee::getname(){
    return NAME;
}

void Employee::set_phone_number(string num){
    this->PHONE_NUMBER = num;
}

string Employee::get_phone_number(){
    return PHONE_NUMBER;
}

void Employee::set_job_position(job pos){
    this->JOB_POSITION = pos;
}

job Employee::get_job_position(){
    return JOB_POSITION;
}

void Employee::set_schedule(working_schedule schedule){
    this->SCHEDULE = schedule;
}

working_schedule Employee::get_schedule(){
    return SCHEDULE;
}

int Employee::get_ID(){
    return ID;
}

//--------------------------------------------------------------------//

class EmployeeManager{
    private:
        User user;
        bool check_log_in;
        vector<Employee> database_employee;
    public:
        void add_employee(Employee new_employer);
        bool edit_name_employee(int ID, string name);
        bool edit_phone_number_employee(int ID, string phone);
        bool edit_job_employee(int ID, job new_job);
        bool edit_schedule_employee(int ID, working_schedule schedule);
        bool delete_employee(int ID);
        vector<Employee> &get_database_employee();
        bool get_check_log_in(string name, string password);
};

void EmployeeManager::add_employee(Employee new_employer){
    database_employee.push_back(new_employer);
}

bool EmployeeManager::edit_name_employee(int ID, string name){
    for (auto i = 0; i < database_employee.size(); i++)
    {
        if (database_employee[i].get_ID() == ID)
        {
            database_employee[i].setname(name);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::edit_phone_number_employee(int ID, string phone){
    for (auto i = 0; i < database_employee.size(); i++)
    {
        if (database_employee[i].get_ID() == ID)
        {
            database_employee[i].set_phone_number(phone);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::edit_job_employee(int ID, job new_job){
    for (auto i = 0; i < database_employee.size(); i++)
    {
        if (database_employee[i].get_ID() == ID)
        {
            database_employee[i].set_job_position(new_job);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::edit_schedule_employee(int ID, working_schedule schedule){
    for (auto i = 0; i < database_employee.size(); i++)
    {
        if (database_employee[i].get_ID() == ID)
        {
            database_employee[i].set_schedule(schedule);
            return true;
        }
        
    }
    return false;

}

bool EmployeeManager::delete_employee(int ID){
    for (auto i = 0; i < database_employee.size(); i++)
    {
        if (database_employee[i].get_ID() == ID)
        {
            database_employee.erase(database_employee.begin()+i);
            return true;
        }
        
    }
    return false;
}

vector<Employee>& EmployeeManager::get_database_employee(){
    return database_employee;
}

bool EmployeeManager::get_check_log_in(string name, string password){
    if (user.check(name, password) || password == "admin")
    {
        check_log_in = true;
    }else check_log_in = false;
    return check_log_in;
}

//--------------------------------------------------------------------//

class SecurityManagement {
    private:
        User user;
        vector<User> databaseUser;
        bool checkSignup;
    public:
        void addUser(string inputUsername, string inputPassword);
        void eraseUser(string inputUsername);
        void editUser(string inputUserName, string inputPassword);
        void setPasswordManager(string inputPassword) {
            user.setPassword(inputPassword);
        };
        bool getCheckSignup (string inputUserName, string inputPassword) {
            if (user.check(inputUserName, inputPassword)) return true;
            else return false;
        };
        vector<User>& getDatabaseUser() {
            return databaseUser;
        };
};

void SecurityManagement::addUser (string inputUsername, string inputPassword) {
    User user = {inputUsername, inputPassword};
    databaseUser.push_back(user);
}

void SecurityManagement::eraseUser (string inputUsername) {
    for (auto i = databaseUser.begin(); i < databaseUser.end(); i++) {
        if (i->getUserName() == inputUsername) databaseUser.erase(i);
    }
}

void SecurityManagement::editUser (string inputUserName, string inputPassword) {
    for (uint8_t i = 0; i < databaseUser.size(); i++) {
        if (databaseUser[i].getUserName() == inputUserName) databaseUser[i].setPassword(inputPassword);
    }
}

void print_security(SecurityManagement& securitymanagement){
    int key;
    auto i =securitymanagement.getDatabaseUser();
    cout<<"----------------USER--------------"<<endl;
    for (auto temp = i.begin(); temp != i.end(); temp++)
    {
        cout<<"USERNAME: "<<temp->getUserName()<<endl;
        cout<<"PASSWORD: "<<temp->getPassword()<<endl;
    }
}


void addUser (SecurityManagement& securitymanagement) {
    int key = 0;
    string username;
    string password;
    do
    {
        system("CLS");
        cout << "ENTER USERNAME: "; cin >> username;
        cout << "ENTER PASSWORD: "; cin >> password;

        securitymanagement.addUser(username, password);
        cout << "_____ADD USER COMPLETED_____"<<endl;
        print_security(securitymanagement);
        cout<<"PRESS 1 TO ADD ANOTHER"<<endl;
        cout<<"PRESS 0 TO GO BACK"<<endl;
        cin>>key;
    } while (key != 0);
    
}

void delUser(SecurityManagement& securitymanagement){
    int key = 0;
    string username;
    do
    {
        int count = 0;
        system("CLS");
        print_security(securitymanagement);
        cout << "ENTER USERNAME: "; cin >> username;
        for (auto i = 0; i < securitymanagement.getDatabaseUser().size(); i++)
        {
            if (username == securitymanagement.getDatabaseUser()[i].getUserName())
            {
                securitymanagement.eraseUser(username);
                cout<<"DELETE USER SUCCESS"<<endl;
                count = 1;
            } 
            
        }
        if (count == 0)
        {
            cout<<"DO NOT HAVE THAT USER"<<endl;
        }

        cout<<"PRESS 1 TO DELETE ANOTHER"<<endl;
        cout<<"PRESS 0 TO GO BACK"<<endl;
        cin>>key;
    } while (key != 0);
    
}

void editPasswordOfManager (SecurityManagement& securitymanagement) {

    string password;
    string passwordAgain; 

    while (1) {
        cout << "\nENTER NEW PASSWORD: ";
        cin >> password;
        cout << "ENTER NEW PASSWORD AGAIN: ";
        cin >> passwordAgain;
        if (passwordAgain == password) break;
        else cout << "\npassword again is error, enter again!";  
    }

    securitymanagement.setPasswordManager(password);
    cout << "_____successfully_____\n\n";
}

void editPasswordofStaff(SecurityManagement& securitymanagement) {
    int key = 0;
    string username;
    string password;
    string new_pass;
    string repass;
    do
    {
        int count = 0;
        system("CLS");
        print_security(securitymanagement);
        cout << "ENTER USERNAME: "; cin >> username;
        cout << "ENTER PASSWORD: "; cin >> password;
        for (auto i = 0; i < securitymanagement.getDatabaseUser().size(); i++)
        {
            if (username == securitymanagement.getDatabaseUser()[i].getUserName() && password == securitymanagement.getDatabaseUser()[i].getPassword())
            {
                while (1)
                {
                    cout << "\nENTER NEW PASSWORD: ";
                    cin >> new_pass;
                    cout << "ENTER NEW PASSWORD AGAIN: ";
                    cin >> repass;
                    if (new_pass == repass) break;
                    else cout << "\nERROR. ENTER PASSWORD AGAIN !"<<endl;  
                }
                
                count = 1;
                securitymanagement.editUser(username, new_pass);
                cout<<"CHANGE PASSWORD COMPLETED"<<endl;
                break;
            } 
            
        }
        if (count == 0)
        {
            cout<<"USERNAME OR PASSWORD IS NOT CORRECT"<<endl;
        }

        cout<<"PRESS 1 TO CHANGE ANOTHER"<<endl;
        cout<<"PRESS 0 TO GO BACK"<<endl;
        cin>>key;
    } while (key != 0);
}

//--------------------------------------------------------------------//

class ServiceManager {
    private:
        typeService service;
    public:
        ServiceManager(int ID = 100, double price = 500, typeStatus status = (typeStatus)0) {
            this->service.ID_Room = ID;
            this->service.Restaurant_Price = price;
            this->service.Restaurant_Status = status;
        }

        void set_Res_Status(typeStatus status) {
            service.Restaurant_Status = status;
        }
        typeStatus get_Res_Status() {
            return service.Restaurant_Status;
        }
        void set_Res_Price(double price) {
            service.Restaurant_Price = price;
        }
        double get_Res_Price() {
            return service.Restaurant_Price;
        }
        void setNumberRoomBookNhaHang(int numberRoom) {
            service.ID_Room = numberRoom;
        }
        int get_ID(){
            return service.ID_Room;
        }
        typeService& get_Service() {
            return service;
        }
};

//--------------------------------------------------------------------//

typedef enum{
    AWFUL = 1,
    BAD,
    NORMAL,
    GOOD,
    EXCELLENT
}type_review;

class review{
    private:
        string NAME;
        string PHONE_NUMBER;
        type_review ROOM;
        type_review STAFF;
        type_review SERVICE;
    public:
        review(string name, string phone, type_review room, type_review staff, type_review service){
            this->NAME = name;
            this->PHONE_NUMBER = phone;
            this->ROOM = room;
            this->SERVICE = service;
            this->STAFF = staff;
        }
        string getname(){
            return NAME;
        }
        string getphone(){
            return PHONE_NUMBER;
        }
        type_review getroom(){
            return ROOM;
        }
        type_review getservice(){
            return SERVICE;
        }
        type_review getstaff(){
            return STAFF;
        }
};

void add_review(vector<review> &database_review){
    system("CLS");
    cout<<"ENTER YOUR NAME: "<<endl;
    string name;
    cin>>name;
    cout<<"ENTER YOUR PHONE NUMBER: "<<endl;
    string phone;
    cin>>phone;

    int room;
    int service;
    int staff;

    do
    {
        cout<<"ENTER NUMBER FOR ROOM QUALITY REVIEW: "<<endl;
        cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
        cin>>room;
    } while (room < 1 || room > 5);

    do
    {
        cout<<"ENTER NUMBER FOR SERVICE QUALITY REVIEW: "<<endl;
        cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
        cin>>service;
    } while (service < 1 || service > 5);

    do
    {
        cout<<"ENTER NUMBER FOR STAFF QUALITY REVIEW: "<<endl;
        cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
        cin>>staff;
    } while (staff < 1 || staff > 5);

    review new_review(name,phone,(type_review)room,(type_review)staff,(type_review)service);
    database_review.push_back(new_review);
    
}

void print_review(vector<review> &database_review){
    cout<<"---------------------CUSTOMER'S REVIEW---------------------"<<endl;
    cout<<"|\tName\t|\tPhone\t|\tRoom_Review\t|\tService_Review\t|\tStaff_Review\t|\n";
    for (auto i = 0; i < database_review.size(); i++)
    {
        cout<<"\t"<<database_review[i].getname()<<"\t|";
        cout<<"\t"<<database_review[i].getphone()<<"\t|";
        cout<<"\t\t"<<(int)database_review[i].getroom()<<"\t|";
        cout<<"\t\t"<<(int)database_review[i].getservice()<<"\t|";
        cout<<"\t\t"<<(int)database_review[i].getstaff()<<"\t|";
        cout<<endl;
    }
    cout<<"1: AWFUL 2: BAD 3: NORMAL 4: GOOD 5: EXCELLENT"<<endl;
}

//--------------------------------------------------------------------//

void print_room(vector<Room> &database_room){
    cout<<"\n\n ------------------ROOM------------------\nRoom   |";
    for (int i = 0; i < database_room.size(); i++)
    {
        printf("  %d  |",database_room[i].get_ID());
    }
    
    cout<<"\nStatus |";
    for (int i = 0; i < database_room.size(); i++)
    {
        if (database_room[i].isAvailable() == true) cout<<"  o  |";
       else cout<<"  X  |";
        
    }
    cout<<"\n";
}

void book_room(vector<Room> &database_room, CustomerManager &database_customer){
    print_room(database_room);

    cout<<"ENTER THE ROOM NUMBER: "<<endl;
    int num = 0;
    cin>>num;
    for (int i = 0; i < database_room.size(); i++)
    {
        if (database_room[i].get_ID() == num)
        {
            if (database_room[i].isAvailable())
            {
                database_room[i].bookRoom();
                database_room[i].checkIn();

                string name;
                string phone_number;
                string address;

                cout<<"Customer's name: ";
                cin>>name;

                cout<<"Customer's phone number: ";
                cin>>phone_number;

                cout<<"Customer's address: ";
                cin>>address;

                uint8_t day = 0;
                uint8_t month = 0;
                uint8_t year = 0;
                cout<<"day: "; cin>>day; fflush(stdin);
                cout<<"month: "; cin>>month; fflush(stdin);
                cout<<"year: "; cin>>year; fflush(stdin);

                uint8_t hour = 0;
                uint8_t minute = 0;
                uint8_t second = 0;
                cout<<"hour: "; cin>>hour; fflush(stdin);
                cout<<"minute: "; cin>>minute; fflush(stdin);
                cout<<"second: "; cin>>second; fflush(stdin);

            Customer new_customer(name,phone_number,address,num);

                bookingHistory booking_data;
                booking_data.date.day = day;
                booking_data.date.month = month;
                booking_data.date.year = year;
                booking_data.time.hour = hour;
                booking_data.time.minute = minute;
                booking_data.time.second =second;

                new_customer.add_booking_history(booking_data);
                database_customer.add_customer(new_customer);
            } else cout<<"THE ROOM IS NOT AVAILABLE"<<endl;
       }
        
    }
    
}

void print_customer_information(vector<Customer> &databaseCustomer){
    cout<<"---------------------CUSTOMER'S INFORMATION---------------------"<<endl;
    cout<<"|\tRoom's ID\t|\tName\t|\tPhone\t|\tAddress\t|\n";
    for (auto i = 0; i < databaseCustomer.size(); i++)
    {
        printf("|\t\t%d\t|",databaseCustomer[i].getID());
        cout<<"\t"<<databaseCustomer[i].getname()<<"\t|";
        cout<<"\t"<<databaseCustomer[i].getphonenumber()<<"\t|";
        cout<<"\t"<<databaseCustomer[i].getaddress()<<"\t|";
        cout<<endl;
    }
    
    
}

void set_quantity_room(vector<Room> &database_room, int quantity){
    for (int i = 0; i < quantity; i++)
    {
        Room room(i);
        database_room.push_back(room);
    }
    cout<<"SET QUANTITY ROOM COMPLETED"<<endl;
    
}

void Edit_Customer_ID_Room(vector<Room> &database_room,vector<ServiceManager> &database_service,CustomerManager &customer_manager){
    int id_change = 0;
    int id_current = 0;

    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomer());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    do
    {
        system("CLS");
        print_room(database_room);
        cout<<"Enter the ID's Room want to change: "<<endl;
        cin>>id_change;
    } while (id_change >  database_room.size() || id_change < 0);
    
    if (database_room[id_change].isAvailable())
    {
        customer_manager.edit_customer_ID_Room(database_room,id_current,id_change);
        for (auto i = 0; i < database_service.size(); i++)
        {
            if (database_service[i].get_ID() == id_current)
            {
                database_service[i].setNumberRoomBookNhaHang(id_change);
                break;
            }
            
        }
        
        cout<<"EDIT COMPLETED"<<endl;
    } else printf("Cannot change to that room \n");
}

void Edit_Customer_Name(vector<Room> &database_room,CustomerManager &customer_manager){
    int id_current;
    string new_name;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomer());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    cout<<"Rename Customer: "<<endl;
    cin>>new_name;
    customer_manager.edit_customer_name(id_current,new_name);
}

void Edit_Customer_Phone_Number(vector<Room> &database_room,CustomerManager &customer_manager){
    int id_current;
    string new_phone_number;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomer());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    cout<<"Enter new phone number: "<<endl;
    cin>>new_phone_number;
    customer_manager.edit_customer_phone(id_current,new_phone_number);
}

void Edit_Customer_Address(vector<Room> &database_room,CustomerManager &customer_manager){
    int id_current;
    string new_address;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomer());
        cout<<"Enter the Customer ID's Room"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

    cout<<"Enter new address: "<<endl;
    cin>>new_address;
    customer_manager.edit_customer_address(id_current,new_address);
}

void Edit_Customer_Func(vector<Room> &database_room, vector<ServiceManager> &database_service, CustomerManager &customer_manager){
    int key = 0;
    int temp = 0;
    bool loop = true;

    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"PRESS 1 TO EDIT CUSTOMER ID'S ROOM "<<endl;
            cout<<"PRESS 2 TO RENAME CUSTOMER "<<endl;
            cout<<"PRESS 3 TO EDIT CUSTOMER'S PHONE NUMBER "<<endl;
            cout<<"PRESS 4 TO EDIT CUSTOMER'S ADDRESS "<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key < 0 || key > 4);

        switch (key)
        {
        case 0:
            loop = false;
            break;
        
        case 1:
            Edit_Customer_ID_Room(database_room,database_service,customer_manager);
            print_room(database_room);
            print_customer_information(customer_manager.getdatabaseCustomer());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;

        case 2:    
            Edit_Customer_Name(database_room, customer_manager);
            print_customer_information(customer_manager.getdatabaseCustomer());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;

        case 3:    
            Edit_Customer_Phone_Number(database_room, customer_manager);
            print_customer_information(customer_manager.getdatabaseCustomer());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;

        case 4:
            Edit_Customer_Address(database_room, customer_manager);
            print_customer_information(customer_manager.getdatabaseCustomer());
            do
            {
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>temp;
            } while (temp != 0);
            break;


        default:
            break;
        }
    }
    
}

void Delete_Customer(vector<Room> &database_room, CustomerManager &customer_manager){
    int id_current;
    int key;
    vector<Customer>::iterator it;
    do
    {
        system("CLS");
        print_customer_information(customer_manager.getdatabaseCustomer());
        cout<<"Enter the Customer ID's Room want to delete information"<<endl;
        cin>>id_current;
    } while (database_room[id_current].isAvailable() == true);

        customer_manager.delete_customer(database_room, id_current);

        do
        {
            system("CLS");
            print_customer_information(customer_manager.getdatabaseCustomer());
            print_room(database_room);
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key != 0);    
    
}

void add_employee(EmployeeManager& employee_manager ){
    string name;
    string phone_number;
    system("CLS");
    cout<<"ENTER THE STAFF'S NAME: "<<endl;
    cin>> name;
    cout<<"ENTER THE STAFF'S PHONE NUMBER: "<<endl;
    cin>> phone_number;

    job postion;
    int key = 0;

    do
    {
        cout<<"0 FOR JANITOR, 1 FOR RECEPTIONIST, 2 FOR LAUNDRY_STAFF, 3 FOR LAUGGAGE_STAFF, 4 FOR GRADENER"<<endl;
        cout<<"CHOOSE THE POSITION: "<<endl;
        cin>>key;
    } while (key < 0 || key > 4);

    switch (key)
    {
    case 0:
        postion = JANITOR;
        break;
    
    case 1:
        postion = RECEPTIONIST;
        break;
    
    case 2:
        postion = LAUNDRY_STAFF;
        break;

    case 3:
        postion = LAUGGAGE_STAFF;
        break;

    case 4:
        postion = GRADENER;
        break;
    default:
        break;
    }

    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    cout<<"ENTER WORKING SCHEDULE"<<endl;
    cout << "day: "; cin >> day; fflush(stdin);
    cout << "month: "; cin >> month;fflush(stdin);
    cout << "year: "; cin >> year;fflush(stdin);
    cout << "hour: "; cin >> hour; fflush(stdin);
    cout << "minute: "; cin >> minute;fflush(stdin);
    cout << "second: "; cin >> second;fflush(stdin);
    working_schedule schedule;
    schedule.date = {day, month, year};
    schedule.time = {hour, minute, second};

    Employee newer(name, phone_number, postion, schedule);
    employee_manager.add_employee(newer);
}

void print_employee(vector<Employee> database_employee){
    cout<<"---------------------EMPLOYEE'S INFORMATION---------------------"<<endl;
    cout<<"JOB DESCRIBTION: 0 FOR JANITOR, 1 FOR RECEPTIONIST, 2 FOR LAUNDRY_STAFF, 3 FOR LAUGGAGE_STAFF, 4 FOR GRADENER"<<endl;
    cout<<"|\tID\t|\tName\t|\tPhone\t|\tJob_Position\t|\tWorking_Schedule\t|\n";
    for (auto i = 0; i < database_employee.size(); i++)
    {
        printf("|\t%d\t|",database_employee[i].get_ID());
        cout<<"\t"<<database_employee[i].getname()<<"\t|";
        cout<<"\t"<<database_employee[i].get_phone_number()<<"\t|";
        cout<<"\t\t"<<database_employee[i].get_job_position()<<"\t|";
        cout<<"\t"<<database_employee[i].get_schedule().date.day<<"-"<<database_employee[i].get_schedule().
        date.month<<"-"<<database_employee[i].get_schedule().date.year<<", "<<database_employee[i].get_schedule().time.hour<<
        ":"<<database_employee[i].get_schedule().time.minute<<":"<<database_employee[i].get_schedule().time.second<<"\t|";
        cout<<endl;
    
    }
    
}

void edit_employee_name(EmployeeManager &employeemanager){
    int ID;
    string rename;
    print_employee(employeemanager.get_database_employee());
    cout<<"Enter employee's ID: "<<endl;
    cin>>ID;
    cout<<"Enter the employee's name: "<<endl;
    cin>>rename;
    if (employeemanager.edit_name_employee(ID, rename))
    {
       cout<<"EDIT SUCCESS"<<endl;
       print_employee(employeemanager.get_database_employee());
    } else cout<<"NOT HAVE THAT ID"<<endl;

}

void edit_employee_phone_number(EmployeeManager &employeemanager){
    int ID;
    string phone;
    print_employee(employeemanager.get_database_employee());
    cout<<"Enter employee's ID: "<<endl;
    cin>>ID;
    cout<<"Enter the employee's phone number: "<<endl;
    cin>>phone;
    if (employeemanager.edit_phone_number_employee(ID, phone))
    {
       cout<<"EDIT SUCCESS"<<endl;
       print_employee(employeemanager.get_database_employee());
    } else cout<<"NOT HAVE THAT ID"<<endl;

}

void edit_employee_job_position(EmployeeManager &employeemanager){
    int ID;
    int key;
    job postion;
    print_employee(employeemanager.get_database_employee());
    cout<<"Enter employee's ID: "<<endl;
    cin>>ID;

    do
    {
        cout<<"0 FOR JANITOR, 1 FOR RECEPTIONIST, 2 FOR LAUNDRY_STAFF, 3 FOR LAUGGAGE_STAFF, 4 FOR GRADENER"<<endl;
        cout<<"CHOOSE THE POSITION: "<<endl;
        cin>>key;
    } while (key < 0 || key > 4);

    switch (key)
    {
    case 0:
        postion = JANITOR;
        break;
    
    case 1:
        postion = RECEPTIONIST;
        break;
    
    case 2:
        postion = LAUNDRY_STAFF;
        break;

    case 3:
        postion = LAUGGAGE_STAFF;
        break;

    case 4:
        postion = GRADENER;
        break;
    default:
        break;
    }

    if (employeemanager.edit_job_employee(ID, postion))
    {
       cout<<"EDIT SUCCESS"<<endl;
       print_employee(employeemanager.get_database_employee());
    } else cout<<"NOT HAVE THAT ID"<<endl;

}

void edit_working_schedule(EmployeeManager &employeemanager){
    int ID;
    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    working_schedule schedule;
    print_employee(employeemanager.get_database_employee());
    cout<<"Enter employee's ID: "<<endl;
    cin>>ID;
    cout<<"ENTER WORKING SCHEDULE"<<endl;
    cout << "day: "; cin >> day; fflush(stdin);
    cout << "month: "; cin >> month;fflush(stdin);
    cout << "year: "; cin >> year;fflush(stdin);
    cout << "hour: "; cin >> hour; fflush(stdin);
    cout << "minute: "; cin >> minute;fflush(stdin);
    cout << "second: "; cin >> second;fflush(stdin);
    schedule.date = {day, month, year};
    schedule.time = {hour, minute, second};
    if (employeemanager.edit_schedule_employee(ID, schedule))
    {
       cout<<"EDIT SUCCESS"<<endl;
       print_employee(employeemanager.get_database_employee());
    } else cout<<"NOT HAVE THAT ID"<<endl;

}

void delete_employee(EmployeeManager &employeemanager){
    int ID;
    print_employee(employeemanager.get_database_employee());
    cout<<"Enter employee's ID: "<<endl;
    cin>>ID;
    if (employeemanager.delete_employee(ID))
    {
       cout<<"DELETE SUCCESS"<<endl;
       print_employee(employeemanager.get_database_employee());
    } else cout<<"NOT HAVE THAT ID"<<endl;
}






void reservation_manager(vector<Room> &database_room, CustomerManager &database_customer){
    int again = true;
    int temp;
    int loop = true;
    while (again)
    {
        loop = true;
        do
        {
            system("CLS");
            cout<<"------------------RESERVATION MANAGER FUNCTION------------------"<<endl;
            cout<<"PRESS 1 TO PRINT THE ROOM STATUS"<<endl;
            cout<<"PRESS 2 TO BOOK ROOM"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>temp;
        } while (temp != 0 && temp != 1 && temp != 2);
        
        switch (temp)
        {
        case 0:
            again = false;
            break;
        case 1:
            while (loop)
            {
                print_room(database_room);
                do
                {
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>loop;
                } while (loop != 0);
            }
            break;
        case 2:
            while (loop)
            {
                book_room(database_room, database_customer);
                do
                {
                    system("CLS");
                    cout<<"PRESS 1 TO BOOK ANOTHER ROOM"<<endl;
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>loop;
                } while (loop != 0 && loop != 1);
            }
            break;  
        default:
            break;
        }
    }
    
}



void customer_manager(vector<Room> &database_room, vector<ServiceManager> &database_service, CustomerManager &database_customer){
    int key = 0;
    bool loop = true;
    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"------------------CUSTOMER MANAGER FUNCTION------------------"<<endl;
            cout<<"PRESS 1 TO EDIT CUSTOMER'S INFORMATION"<<endl;
            cout<<"PRESS 2 TO DELETE CUSTOMER'S INFORMATION"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key != 0 && key != 1 && key != 2);
        
        switch (key)
        {
        case 0:
            loop = false;
            break;

        case 1:
            Edit_Customer_Func(database_room, database_service, database_customer);
            break;

        case 2:
            Delete_Customer(database_room, database_customer);
            break;

        default:
            break;
        }
    }
    
}

void manager_func(EmployeeManager &employeemanager){
    bool loop = true;
    int key = 0;
    bool again = true;
    bool i;
    string name;
    string pass;

    while (loop)
    {
        do
        {
            cout<<"Enter username: "<<endl;
            cin>>name;
            cout<<"Enter password: "<<endl;
            cin>>pass;

            if (employeemanager.get_check_log_in(name, pass))
            {
                cout<<"Log in success"<<endl;
            } else 
            {
                int temp = 0;
                cout<<"Username or Password is not right."<<endl;
                do
                {
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>temp;
                } while (temp != 0);
                return;
            }
            
        } while (employeemanager.get_check_log_in(name, pass) != true);

        while (again)
        {
            do
            {
                system("CLS");
                cout<<"------------------MANAGER FUNCTION------------------"<<endl;
                cout<<"PRESS 1 TO ADD NEW EMPLOYEE"<<endl;
                cout<<"PRESS 2 TO EDIT EMPLOYEE'S NAME"<<endl;
                cout<<"PRESS 3 TO EDIT EMPLOYEE'S PHONE NUMBER"<<endl;
                cout<<"PRESS 4 TO EDIT EMPLOYEE'S JOB POSITION"<<endl;
                cout<<"PRESS 5 TO EDIT EMPLOYEE'S WORKING SCHEDULE"<<endl;
                cout<<"PRESS 6 TO DELETE EMPLOYEE"<<endl;
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>key;
            } while (key < 0 || key > 6);
            
            switch (key)
            {
            case 0:
                loop = false;
                again = false;
                break;
            
            case 1:
                i = true;
                while (i)
                {
                    do
                    {
                        add_employee(employeemanager);
                        system("CLS");
                        print_employee(employeemanager.get_database_employee());
                        cout<<"PRESS 1 TO ADD ANOTHER"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>key;
                    } while (key != 0 && key != 1);

                    switch (key)
                    {
                    case 0:
                        i = false;
                        break;
                    
                    default:
                        break;
                    }       
                }
                break;

            case 2:
                i = true;
                while (i)
                {
                    do
                    {
                        system("CLS");
                        edit_employee_name(employeemanager);
                        cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>key;
                    } while (key != 0 && key != 1);

                    switch (key)
                    {
                    case 0:
                        i = false;
                        break;
                    
                    default:
                        break;
                    }
                    
                }
                break;

            case 3:
                i = true;
                while (i)
                {
                    do
                    {
                        system("CLS");
                        edit_employee_phone_number(employeemanager);
                        cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>key;
                    } while (key != 0 && key != 1);

                    switch (key)
                    {
                    case 0:
                        i = false;
                        break;
                    
                    default:
                        break;
                    }
                    
                }
                break;

            case 4:
                i = true;
                while (i)
                {
                    do
                    {
                        system("CLS");
                        edit_employee_job_position(employeemanager);
                        cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>key;
                    } while (key != 0 && key != 1);

                    switch (key)
                    {
                    case 0:
                        i = false;
                        break;
                    
                    default:
                        break;
                    }
                    
                }
                break;

            case 5:
                i = true;
                while (i)
                {
                    do
                    {
                        system("CLS");
                        edit_working_schedule(employeemanager);
                        cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>key;
                    } while (key != 0 && key != 1);

                    switch (key)
                    {
                    case 0:
                        i = false;
                        break;
                    
                    default:
                        break;
                    }
                    
                }
                break;

            case 6:
                i = true;
                while (i)
                {
                    do
                    {
                        system("CLS");
                        delete_employee(employeemanager);
                        cout<<"PRESS 1 TO DELETE ANOTHER"<<endl;
                        cout<<"PRESS 0 TO GO BACK"<<endl;
                        cin>>key;
                    } while (key != 0 && key != 1);
                    
                    switch (key)
                    {
                    case 0:
                        i = false;
                        break;
                    
                    default:
                        break;
                    }
                }
                break;

            default:
                break;
            }
        }
        
    }
}

void securityManagement (SecurityManagement& securitymanagement) {
    bool checkSignup;
    bool loop = true;
    bool again = true;
    int key = 0;

    while (loop)
    {
        do
        {
            cout << "\n_______ ENTER USERNAME, PASSWORD _______\n";
            string username;
            string password;
            cout << "ENTER USERNAME: "<<endl; cin >> username;
            cout << "ENTER PASSWORD: "<<endl;; cin >> password;
            checkSignup = securitymanagement.getCheckSignup(username, password);
            if(checkSignup == false) {
            cout << "USERNAME OR PASSWORD IS NOT CORRECT"<< endl;
            cout<<"PRESS 1 TO TRY AGAIN"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
            
            switch (key)
            {
            case 0:
                return;
                break;
            
            default:
                break;
            }
        }
        } while (checkSignup == false);

        while (again)
        {
            do
            {
                system("CLS");
                cout<<"------------------MANAGER_FUNCTION------------------"<<endl;
                cout << "PRESS 1 TO ADD USER: "<<endl;
                cout << "PRESS 2 TO DELETE USER"<<endl;
                cout << "PRESS 3 TO CHANGE USER'S PASSWORD"<<endl;
                cout << "PRESS 4 TO CHANGE MANAGER'S PASSWORD"<<endl;
                cout << "PRESS 0 TO GO BACK"<<endl;
                cin >> key;
            } while (key < 0 || key > 4);
            
            switch (key)
            {
            case 0:
                return;
                break;

            case 1:
                addUser(securitymanagement);
                break;

            case 2:
                delUser(securitymanagement);
                print_security(securitymanagement);
                break;
            case 3:
                editPasswordofStaff(securitymanagement);
                break;    
            case 4:
                editPasswordOfManager(securitymanagement);
                break;
            default:
                break;
            }
        }
        
    }    

}

void staff_func(EmployeeManager &employeemanager, SecurityManagement& securitymanagement){
    bool loop = true;
    int key = 0;
    bool again = true;
    bool i;
    string username;
    string password;
    uint8_t checkUsername = 0;
    uint8_t checkPassword = 0;

    while (loop)
    {
        do
        {
            cout << "ENTER USERNAME: "<<endl;; cin >> username;
            cout << "ENTER PASSWORD: "<<endl;; cin >> password;
            for (uint8_t i = 0; i < securitymanagement.getDatabaseUser().size(); i++) {
                if (securitymanagement.getDatabaseUser()[i].getUserName() == username) {
                    checkUsername++;
                    if (securitymanagement.getDatabaseUser()[i].getPassword() == password)
                    {
                        checkPassword++;
                        break;
                    } 
                    else {
                        cout << "PASSWORD IS NOT CORRECT !\n";
                    }
                }
        }
        if (checkUsername == 0) {
            cout << "USERNAME IS NOT CORRECT !\n";
        }

        int key;

        if (checkPassword == 0 || checkUsername == 0)
        {
            do
            {
                cout<<"PRESS 1 TO TRY AGAIN"<<endl;
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>key;
            } while (key != 0 && key != 1);

            switch (key)
            {
            case 0:
                return;
                break;
            
            default:
                break;
            }
        }

        } while (checkPassword == 0 || checkUsername == 0);
            while (again)
            {
                do
                {
                    system("CLS");
                    cout<<"------------------STAFF_FUNCTION------------------"<<endl;
                    cout<<"PRESS 1 TO EDIT EMPLOYEE'S PHONE NUMBER"<<endl;
                    cout<<"PRESS 2 TO EDIT EMPLOYEE'S WORKING SCHEDULE"<<endl;
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>key;
                } while (key < 0 || key > 6);
                
                switch (key)
                {
                case 0:
                    loop = false;
                    again = false;
                    break;

                case 1:
                    i = true;
                    while (i)
                    {
                        do
                        {
                            system("CLS");
                            edit_employee_phone_number(employeemanager);
                            cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
                            cout<<"PRESS 0 TO GO BACK"<<endl;
                            cin>>key;
                        } while (key != 0 && key != 1);

                        switch (key)
                        {
                        case 0:
                            i = false;
                            break;
                        
                        default:
                            break;
                        }
                        
                    }
                    break;

                case 2:
                    i = true;
                    while (i)
                    {
                        do
                        {
                            system("CLS");
                            edit_working_schedule(employeemanager);
                            cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
                            cout<<"PRESS 0 TO GO BACK"<<endl;
                            cin>>key;
                        } while (key != 0 && key != 1);

                        switch (key)
                        {
                        case 0:
                            i = false;
                            break;
                        
                        default:
                            break;
                        }
                        
                    }
                    break;

                default:
                    break;
                }
            }
        }
}

void employee_manager(EmployeeManager &employeemanager, SecurityManagement &securitymanagement){
    int key = 0;
    bool loop = true;
    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"------------------EMPLOYEE MANAGER FUNCTION------------------"<<endl;
            cout<<"PRESS 1 IF YOU ARE MANAGER"<<endl;
            cout<<"PRESS 2 IF YOU ARE STAFF"<<endl;
            cout<<"PRESS 0 TO GO BACK";
            cin>>key;
        } while (key != 0 && key != 1 && key != 2);

        switch (key)
        {
        case 0:
            loop = false;
            break;

        case 1:
            manager_func(employeemanager);
            break;

        case 2:
            staff_func(employeemanager, securitymanagement);
            break;
        
        default:
            break;
        }   
    }
    
}

void add_service(vector<ServiceManager> &databaseService, int ID, typeStatus status, double price){
    ServiceManager service = {ID, price, status};
    databaseService.push_back(service);
}

void edit_service(vector<ServiceManager> &databaseService, int ID){
    double price = 0;
    for (auto i = 0; i < databaseService.size(); i++)
    {
        if (databaseService[i].get_ID() == ID)
        {
            cout<<"ENTER THE PRICE OF SERVICE: "<<endl;
            cin>>price;
            databaseService[i].set_Res_Price(price);
            cout<<"EDIT COMPLETED"<<endl;
            return;
        }
        
    }
    cout<<"THAT ROOM HAS NO SERVICE"<<endl;
    
}

void print_service(vector<ServiceManager> &databaseService){
    cout<<"----------------------------SERVICE INFORMATION----------------------------"<<endl;
    cout<<"|\tRoom's ID\t|\tRestaurant Price\t|\tRestaurant Status\t|\n";
    for (auto i = 0; i < databaseService.size(); i++)
    {
        printf("|\t\t%d\t|",databaseService[i].get_ID());
        cout<<"\t\t"<<databaseService[i].get_Res_Price()<<"\t\t|";
        if (databaseService[i].get_Res_Status()== 1)
        {
            cout<<"\t\tOUT\t\t|";
        }else cout<<"\t\tIN\t\t|";
        cout<<endl;
    }
}

void ADD_SERVICE(vector<Room> &databaseRoom, vector<ServiceManager> &databaseService){
    int ID;
    int key = 0;
    bool check = true;
    bool loop = true;
    double price = 0;
    bool check_id = true; 

    while (loop)
    {
        do
        {
            system("CLS");
            print_room(databaseRoom);
            cout<<"ENTER THE ID ROOM NEED ADD SERVICE"<<endl;
            cin>>ID; cin.ignore();
        } while (ID < 0 || ID > databaseRoom.size());

        for (auto i = 0; i < databaseService.size(); i++)
        {
            if (databaseService[i].get_ID() == ID)
            {
                check = false;
                cout<<"THIS ROOM ALREADY HAS ADDED SERVICE"<<endl;
                do
                {
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>key;
                } while (key != 0);
                
                if (key == 0)
                {
                    return;
                }
                
            }
            
        }

        if (check)
        {
            for (auto i = 0; i < databaseRoom.size(); i++)
            {
                if (databaseRoom[i].get_ID() == ID && databaseRoom[i].isAvailable() == false)
                {
                    check_id = false;
                    cout<<"ENTER THE SERVICE'S PRICE:"<<endl;
                    cin>>price; cin.ignore();
                    add_service(databaseService, ID, (typeStatus)0, price);
                    cout<<"ADD SERVICE COMPLETE"<<endl;
                }
                
            }
            
            do
            {
                if (check_id)
                {
                    cout<<"DO NOT HAVE THAT ROOM"<<endl;
                }
                print_service(databaseService);
                cout<< "PRESS 1 TO ADD SERVICE TO ANOTHER ROOM"<<endl;
                cout<< "PRESS 0 TO GO BACK"<<endl;
                cin>>key;
            } while (key != 0 && key != 1);

            switch (key)
            {
            case 0:
                return;
                break;
            
            default:
                break;
            }
        }
        
    }
    
}

void DELETE_SERVICE(vector<ServiceManager> &databaseService, vector<Room> &databaseRoom){
    int ID = 0;
    int key = 0;
    bool check = true;

    while (1)
    {
        do
        {
            system("CLS");
            print_service(databaseService);
            cout<<"ENTER THE ID ROOM NEED DELETE SERVICE"<<endl;
            cin>>ID;
        } while (ID < 0 || ID > databaseRoom.size());

        for (auto i = 0; i < databaseService.size(); i++)
        {
            if (databaseService[i].get_ID() == ID)
            {
                check = false;
                databaseService.erase(databaseService.begin()+i);
                cout<<"DELETE COMPLETE"<<endl;
                break;
            }
            
        }

        if (check)
        {
            cout<<"THAT ROOM NOT HAVE SERVICE"<<endl;
        }

        do
        {
            cout<<"PRESS 1 TO DELETE ANOTHER"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key != 0 && key != 1);

        switch (key)
        {
        case 0:
            return;
            break;
        
        default:
            break;
        }
    }
}

void EDIT_SERVICE(vector<ServiceManager> &databaseService, vector<Room> &databaseRoom){
    int ID = 0;
    int key = 0;
    bool check = true;

    while (1)
    {
        do
        {
            system("CLS");
            print_service(databaseService);
            cout<<"ENTER THE ID ROOM NEED EDIT SERVICE"<<endl;
            cin>>ID;
        } while (ID < 0 || ID > databaseRoom.size());

        edit_service(databaseService, ID);

        do
        {
            cout<<"PRESS 1 TO EDIT ANOTHER"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key != 0 && key != 1);

        switch (key)
        {
        case 0:
            return;
            break;
        
        default:
            break;
        }
    }
}



void service_manager(vector<Room> &databaseRoom, vector<ServiceManager> &databaseService){
    int id_room = 0;
    int key = 0;
    bool loop = true;
    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"------------------SERVICE MANAGER FUNCTION------------------"<<endl;
            cout<<"PRESS 1 TO ADD SERVICE"<<endl;
            cout<<"PRESS 2 TO DELETE SERVICE"<<endl;
            cout<<"PRESS 3 TO EDIT SERVICE"<<endl;
            cout<<"PRESS 4 TO PRINT SERVICE INFORMATION"<< endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key < 0 || key > 4);
        
        switch (key)
        {
        case 0:
            loop = false;
            break;

        case 1:
            ADD_SERVICE(databaseRoom,databaseService);
            break;

        case 2:
            DELETE_SERVICE(databaseService, databaseRoom);
            break;

        case 3:
            EDIT_SERVICE(databaseService, databaseRoom);
            break;

        case 4:
            do
            {   system("CLs");
                print_service(databaseService);
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>key;
            } while (key != 0);
            
            if (key == 0)
            {
                return;
            }
            
        default:
            break;
        }
    }
}

void review_manager(vector<review> &database_review){
    int key = 0;
    bool loop = true;
    bool again = true;
    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"------------------REVIEW MANAGER FUNCTION------------------"<<endl;
            cout<<"PRESS 1 TO ADD REVIEW"<<endl;
            cout<<"PRESS 2 TO PRINT ALL REVIEWS"<< endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key < 0 || key > 2);
        
        switch (key)
        {
        case 0:
            loop = false;
            break;

        case 1:
            while (again)
            {
                do
                {
                    add_review(database_review);
                    cout<<"PRESS 1 TO ADD ANOTHER"<<endl;
                    cout<<"PRESS 0 TO GO BACK"<<endl;
                    cin>>key;
                } while (key != 0 && key != 1);

                switch (key)
                {
                case 0:
                    again = false;
                    break;
                
                default:
                    break;
                }
            }
            break;

        case 2:
            do
            {   system("CLS");
                print_review(database_review);
                cout<<"PRESS 0 TO GO BACK"<<endl;
                cin>>key;
            } while (key != 0);
            
            break;
            
        default:
            break;
        }
    }
}


int main(int argc, char const *argv[])
{
    int count = 0;
    int key;
    bool loop = true;
    vector<Room> database_room;
    vector<ServiceManager> database_service;
    vector<review> database_review;
    CustomerManager customer;
    EmployeeManager employee;
    SecurityManagement security;

    do
    {
        cout<<"ENTER THE NUMBER OF THE ROOM: "<<endl;
        cin>>count;
    } while (count <= 0);
    set_quantity_room(database_room, count);

    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"PRESS 1 TO RESERVATION MANAGER"<<endl;
            cout<<"PRESS 2 TO CUSTOMER MANAGER"<<endl;
            cout<<"PRESS 3 TO EMPLOYEE MANAGER"<<endl;
            cout<<"PRESS 4 TO SECURITY MANAGEMENT"<<endl;
            cout<<"PRESS 5 TO SERVICE MANAGER"<<endl;
            cout<<"PRESS 6 TO REVIEW MANAGER"<<endl;
            cout<<"PRESS 0 TO EXIT"<<endl;
            cin>>key;
        } while (key <0 || key > 6);

        switch (key)
        {
        case 0:
            loop = false;
            break;
        
        case 1:
            reservation_manager(database_room, customer);
            break;

        case 2:
            customer_manager(database_room, database_service, customer);
            break;

        case 3:
            employee_manager(employee,security);
            break;

        case 4:
            securityManagement(security);
            break;
        
        case 5:
            service_manager(database_room, database_service);
            break;

        case 6:
            review_manager(database_review);
            break;

        default:
            break;
        }
        
    }
    
    return 0;
}
