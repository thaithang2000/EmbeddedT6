#include <iostream>


using namespace std;

typedef enum{
    CLOCKWISE,
    COUNTERCLOCKWISE
}typeDirection;

class DCMotor{
    private:
        double voltage;
        double maxCurrent;
        double speed;
        typeDirection direction;
        bool isRunning;
    public:
        void set_speed(double speed){
            this->speed = speed;
        }

        double get_speed(){
            return speed;
        }

        void set_direction(typeDirection direction){
            this->direction = direction;
        }

        typeDirection get_direction(){
            return direction;
        }

        void set_run(){
            this->isRunning = true;
        }

        void set_stop(){
            this->isRunning = false;
        }

        bool get_status(){
            return isRunning;
        }

        void set_maxcurrent(double current){
            this->maxCurrent = current;
        }

        double get_maxcurrent(){
            return maxCurrent;
        }

        void set_voltage(double voltage){
            this->voltage = voltage;
        }

        double get_voltage(){
            return voltage;
        }

};

class FeedbackSystem{
    private:
        double limit_current = 2.5; //Ampe
        double limit_heat = 80; //C
    public:
        void overloadDetected(double motor_current){
            if (motor_current > limit_current)
            {
                cerr<<"WARNING OVERLOAD DETECTED"<<endl;
            }
        }

        void overheatDetected(double motor_heat){
            if(motor_heat > limit_heat)
            {
                cerr<<"WARNING OVERHEAT DETECTED"<<endl;
            }
        }

        void set_current(double current){
            this->limit_current = current;
        }

        double get_current(){
            return limit_current;
        }

        void set_heat(double heat){
            this->limit_heat = heat;
        }

        double get_heat(){
            return limit_heat;
        }
};

class DCMotorController{
    private:
        DCMotor Motor;
        FeedbackSystem System;
    public:
        DCMotor& get_Motor(){
            return Motor;
        }

        FeedbackSystem& get_System(){
            return System;
        }
};

void SET_VOLTAGE(DCMotor& Motor){
    double voltage;
    do
    {
        cout<<"ENTER THE VOLTAGE OF THE MOTOR: "<<endl;
        cin>>voltage;
    } while (voltage <= 0);
    
    Motor.set_voltage(voltage);
    cout<<"SET COMPLETED"<<endl;
}

void SET_MAX_CURRENT(DCMotor& Motor){
    double current;
    do
    {
        cout<<"ENTER THE CURRENT OF THE MOTOR: "<<endl;
        cin>>current;
    } while (current <= 0);
    
    Motor.set_maxcurrent(current);
    cout<<"SET COMPLETED"<<endl;
}

void SET_SPEED(DCMotor& Motor){
    double speed;
    do
    {
        cout<<"ENTER THE SPEED OF THE MOTOR: "<<endl;
        cin>>speed;
    } while (speed <= 0);
    
    Motor.set_speed(speed);
    cout<<"SET COMPLETED"<<endl;
}

void SET_DIRECTION(DCMotor& Motor){
    int direction;
    do
    {
        cout<<"ENTER THE DIRECTION OF THE MOTOR: "<<endl;
        cout<<"0 IS CLOCKWISE 1 IS COUNTER CLOCKWISE"<<endl;
        cin>>direction;
    } while (direction != 0 && direction != 1);

    Motor.set_direction((typeDirection)direction);
    cout<<"SET COMPLETED"<<endl;
}

void SET_RUN_STOP(DCMotor& Motor){
    int status;
    do
    {
        cout<<"ENTER THE STATUS OF THE MOTOR: "<<endl;
        cout<<"0 IS STOP 1 IS RUN"<<endl;
        cin>>status;
    } while (status != 0 && status != 1);

    if (status == 0)
    {
        Motor.set_stop();
    }else Motor.set_run();

    cout<<"SET COMPLETED"<<endl;
    
}

void SET_LIMIT_CURRENT(FeedbackSystem& system){
    double current;
    do
    {
        cout<<"ENTER THE LIMIT CURRENT: "<<endl;
        cin>>current;
    } while (current <= 0);

    system.set_current(current);
    cout<<"SET COMPLETED"<<endl;
}

void SET_LIMIT_HEAT(FeedbackSystem& system){
    double heat;
    do
    {
        cout<<"ENTER THE LIMIT HEAT: "<<endl;
        cin>>heat;
    } while (heat <= 0);

    system.set_heat(heat);
    cout<<"SET COMPLETED"<<endl;
}

void SET_MOTOR(DCMotor& Motor, double& DC_Heat){
    int key = 0;
    double heat = 0;
    bool loop = true;

    while (loop)
    {
        do
        {
            system("CLS");
            cout<<"PRESS 1 TO SET VOLTAGE"<<endl;
            cout<<"PRESS 2 TO SET MAX CURRENT"<<endl;
            cout<<"PRESS 3 TO SET SPEED"<<endl;
            cout<<"PRESS 4 TO SET DIRECTION"<<endl;
            cout<<"PRESS 5 TO SET RUN/STOP"<<endl;
            cout<<"PRESS 6 TO SET HEAT"<<endl;
            cout<<"PRESS 0 TO GO BACK"<<endl;
            cin>>key;
        } while (key < 0 || key > 6);

        switch (key)
        {
        case 0:
            loop = false;
            break;
        
        case 1:
            SET_VOLTAGE(Motor);
            break;

        case 2:
            SET_MAX_CURRENT(Motor);
            break;
        
        case 3:
            SET_SPEED(Motor);
            break;

        case 4:
            SET_DIRECTION(Motor);
            break;

        case 5:
            SET_RUN_STOP(Motor);
            break;
        
        case 6:
            do
            {
                cout<<"ENTER THE MOTOR HEAT: "<<endl;
                cin>>heat;
            } while (heat <= 20);

            DC_Heat = heat;
            break;
            
        default:
            break;
        }
        }
    
}

void PRINT(FeedbackSystem &System, DCMotor& Motor){
    cout<<"-------------------DC_MOTOR_CONTROLLER_INFORMATION----------------------"<<endl;
    cout<<"OVERLOAD_DETECTED: "<<System.get_current()<<endl;
    cout<<"OVERHEAT_DETECTED: "<<System.get_heat()<<endl;
    cout<<"MOTOR VOLTAGE: "<<Motor.get_voltage()<<endl;
    cout<<"MOTOR MAX CURRENT: "<<Motor.get_maxcurrent()<<endl;
    cout<<"MOTOR SPEED: "<<Motor.get_speed()<<endl;
    if (Motor.get_direction()==CLOCKWISE)
    {
        cout<<"MOTOR DIRECTION: CLOCKWISE"<<endl;
    }else cout<<"MOTOR DIRECTION: COUNTER CLOCKWISE"<<endl;
    
    if (Motor.get_status() == 0)
    {
        cout<<"MOTOR STATUS: STOP"<<endl;
    }else cout<<"MOTOR STATUS: RUN"<<endl;
}

int main(int argc, char const *argv[])
{
    int key;
    bool loop = true;
    double Motor_Heat = 0;
    DCMotorController Cotroller;

    while (loop)
    {
        system("CLS");
        PRINT(Cotroller.get_System(),Cotroller.get_Motor());
        Cotroller.get_System().overheatDetected(Motor_Heat);
        Cotroller.get_System().overloadDetected(Cotroller.get_Motor().get_maxcurrent());
        do
        {
            cout<<"PRESS 1 TO SET MOTOR"<<endl;
            cout<<"PRESS 2 TO SET FEEDBACK SYSTEM LIMIT"<<endl;
            cout<<"PRESS 0 TO EXIT"<<endl;
            cin>>key;
        } while (key != 0 && key != 1 && key != 2);

        switch (key)
        {
        case 0:
            loop = false;
            break;
        
        case 1:
            SET_MOTOR(Cotroller.get_Motor(),Motor_Heat);
            break;

        case 2:
            SET_LIMIT_CURRENT(Cotroller.get_System());
            SET_LIMIT_HEAT(Cotroller.get_System());
            break;

        default:
            break;
        }

    }
    

    return 0;
}
