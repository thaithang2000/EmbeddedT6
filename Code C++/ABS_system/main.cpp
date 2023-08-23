#include <iostream>

using namespace std;

class Wheel{
    private:
        double SPEED;  //rpm
    public:
        void set_speed(double speed){
            this->SPEED = speed;
        }

        double get_speed(){
            return SPEED;
        }
};

class Car{
    private:
        Wheel wheel;
        double CAR_WEIGHT = 1000;  //kg
        double CUSTOMER_WEIGHT;
    public:
        void set_car(double weight){
            this->CAR_WEIGHT = weight;
        }

        double get_car(){
            return CAR_WEIGHT;
        }

        void set_customer(double weight){
            this->CUSTOMER_WEIGHT += weight;
        }

        double get_customer(){
            return CUSTOMER_WEIGHT;
        }

        double total(){
            return (CAR_WEIGHT + CUSTOMER_WEIGHT);
        }
        Wheel& get_wheel(){
            return wheel;
        }

};

class ABS{
    private:    
        Car CAR;
        const double LIMIT = 10; //rpm
    public:
        void check(){
            double speed = CAR.get_wheel().get_speed();
            speed -= CAR.total()*0.01;       //the real speed will decrease 1% of total weight 
            if (speed < LIMIT)
            {
                cerr<<"WARING CAR'S SPEED IS LOWER THAN LIMIT"<<endl;
            }
        }

        void set_car(Car &temp){
            this->CAR = temp;
        }
};

void SET_SPEED(Wheel& wheel){
    double speed = 0;
    do
    {
        cout<<"ENTER THE SPEED OF THE WHEEL"<<endl;
        cin>>speed;
    } while (speed < 10);
    wheel.set_speed(speed);
    cout<<"SET COMPLETED"<<endl;
}

void SET_CAR_WEIGHT(Car& car){
    double weight = 0;
    do
    {
        cout<<"ENTER THE WEIGHT OF THE CAR"<<endl;
        cin>>weight;
    } while (weight < 1000);
    car.set_car(weight);
    cout<<"SET COMPLETED"<<endl;
}

void ADD_CUSTOMER(Car& car){
    double weight = 0;
    do
    {
        cout<<"ENTER THE WEIGHT OF THE CUSTOMER"<<endl;
        cin>>weight;
    } while (weight <= 0);
    car.set_customer(weight);
    cout<<"SET COMPLETED"<<endl;
}

void PRINT(Car & car){
    cout<<"------------------------CAR'S INFORMATION------------------------"<<endl;
    cout<<"|\tSPEED\t|\tCAR_WEIGHT\t|\tCUSTOMER_WEIGHT\t|\tTOTAL_WEIGHT\t|"<<endl;
    cout<<"|\t"<<car.get_wheel().get_speed()<<"\t";
    cout<<"|\t\t"<<car.get_car()<<"\t";
    cout<<"|\t\t"<<car.get_customer()<<"\t";
    cout<<"|\t\t"<<car.get_car()+car.get_car()<<"\t|"<<endl;
}

int main(int argc, char const *argv[])
{
    Car New_Car;
    ABS New_ABS;
    int key = 0;
    bool loop = true;

    
   while (loop)
   {
    do
    {
        cout<<"PRESS 1 TO SET CAR'S SPEED"<<endl;
        cout<<"PRESS 2 TO SET CAR'S WEIGHT"<<endl;
        cout<<"PRESS 3 TO ADD CUSTOMER"<<endl;
        cout<<"PRESS 4 TO CHECK ABS SYSTEM"<<endl;
        cout<<"PRESS 0 TO EXIT"<<endl;
        cin>>key;
    } while (key < 0 || key > 4);
    
    switch (key)
    {
    case 0:
        loop = false;
        break;
    
    case 1:
        system("CLS");
        SET_SPEED(New_Car.get_wheel());
        break;

    case 2:
        system("CLS");
        SET_CAR_WEIGHT(New_Car);
        break;    

    case 3:
        system("CLS");
        ADD_CUSTOMER(New_Car);
        break; 

    case 4:
        New_ABS.set_car(New_Car);
        PRINT(New_Car);
        New_ABS.check();
        break;    

    default:
        break;
    }
   }
   
    return 0;
}
