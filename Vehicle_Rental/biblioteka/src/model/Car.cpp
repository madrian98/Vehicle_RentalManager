#include "model/Car.h"
#include <string>

using namespace std;

Car::Car(float price, string registrationNumber, float engineDisplacement, char seg)
        : MotorVehicle(price, std::move(registrationNumber), engineDisplacement), segment(seg){}

string Car::vehicleInfo(){
    string chain;
    chain = "Car: " + MotorVehicle::vehicleInfo() + " Segment: " + segment;
    return chain;
}

float Car::getWage() const{
    float wage = 0;
    if(segment == 'A')
    {
        wage = 1;
    }
    else if(segment == 'B')
    {
        wage = 1.1;
    }
    else if(segment == 'C')
    {
        wage = 1.2;
    }
    else if(segment == 'D')
    {
        wage = 1.3;
    }
    else if(segment == 'E')
    {
        wage = 1.5;
    }
    return wage;
}

float Car::getPrice(){
    return MotorVehicle::getPrice() * getWage();
}
