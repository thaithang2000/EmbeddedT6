#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592654;
const int EARTH_RADIUS = 6371; //km

class GPSPoint{
    private:
        double LATITUDE_A;  //vi do
        double LONGITUDE_A; //kinh do
        double LATITUDE_B;  //vi do
        double LONGITUDE_B;        
    
    public:
        void input(double latitude_a, double longitude_a, double latitude_b, double longitude_b);
        void isValid();
        double toRadian(double variable);
        double distanceTo(); 
};


void GPSPoint::isValid(){
    if (LATITUDE_A < - 90 || LATITUDE_A > 90)
    {
        cerr<<"LATITUDE AT POINT A IS NOT SUITABLE"<<endl;
    }

    if (LONGITUDE_A < - 180 || LONGITUDE_A > 180)
    {
        cerr<<"LONGITUDE AT POINT A IS NOT SUITABLE"<<endl;
    }

    if (LATITUDE_B < - 90 || LATITUDE_B > 90)
    {
        cerr<<"LATITUDE AT POINT B IS NOT SUITABLE"<<endl;
    }

    if (LONGITUDE_B < - 180 || LONGITUDE_B > 180)
    {
        cerr<<"LONGITUDE AT POINT B IS NOT SUITABLE"<<endl;
    }
    
}

void GPSPoint::input(double latitude_a, double longitude_a, double latitude_b, double longitude_b){
    this->LATITUDE_A = latitude_a;
    this->LONGITUDE_A = longitude_a;
    this->LATITUDE_B = latitude_b;
    this->LONGITUDE_B = longitude_b;    
    isValid();
}

double GPSPoint::toRadian(double variable){
    return (variable * (PI/180));
}

double GPSPoint::distanceTo(){
    double distance = 0;
    double A = pow(sin((toRadian(LATITUDE_B - LATITUDE_A))/2),2) + pow(sin((toRadian(LONGITUDE_B - LONGITUDE_A))/2),2) * 
    cos(toRadian(LATITUDE_A)) * cos(toRadian(LATITUDE_B));
    distance = 2 * EARTH_RADIUS * asin(sqrt(A));
    return distance;
}

void ADD(GPSPoint &Point_A){
    double latitude_A;
    double longitude_A;
    double latitude_B;
    double longitude_B;

    do
    {
        cout<<"ENTER THE LATITUDE AT POINT A: "<<endl;
        cin>>latitude_A;
        cout<<"ENTER THE LONGITUDE AT POINT A: "<<endl;
        cin>>longitude_A;
        cout<<"ENTER THE LATITUDE AT POINT B: "<<endl;
        cin>>latitude_B;
        cout<<"ENTER THE LONGITUDE AT POINT B: "<<endl;
        cin>>longitude_B;
        Point_A.input(latitude_A, longitude_A, latitude_B, longitude_B);
    } while ((latitude_A < -90 || latitude_A >90) || (longitude_A < -180 || longitude_A > 180) || (latitude_B < -90 || latitude_B >90) || (longitude_B < -180 || longitude_B > 180));
    
    cout<< "ADD COMPLETED"<<endl;
}

int main(int argc, char const *argv[])
{
    GPSPoint Point_A;

    ADD(Point_A);
    double d = Point_A.distanceTo();
    
    cout<<"Distance from point A to point B is: "<<d<<" km"<<endl;
    return 0;
}

