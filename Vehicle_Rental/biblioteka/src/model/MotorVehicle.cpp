#include "model/MotorVehicle.h"

#include <utility>

using namespace std;

MotorVehicle::MotorVehicle(float price, std::string registrationNumber, float engineCapacity)
        : Vehicle(price, std::move(registrationNumber)), engineDisplacement(engineCapacity){}

MotorVehicle::~MotorVehicle()= default;

float MotorVehicle::getEngineDisplacement() const{
    return engineDisplacement;
}

std::string MotorVehicle::vehicleInfo(){
    std::string chain;
    chain = Vehicle::vehicleInfo() + " Engine capacity: " + to_string(engineDisplacement);
    return chain;
}

float MotorVehicle::getWage() const{
    float wage = 0;
    if (engineDisplacement < 1000)
    {
        wage = 1;
    }
    else if (engineDisplacement >= 1000 and engineDisplacement < 2000)
    {
        wage = 1 + (engineDisplacement - 1000) / 1000 * 0.5;
    }
    else if (engineDisplacement >= 2000)
    {
        wage = 1.5;
    }
    return wage;
}

float MotorVehicle::getPrice(){
    return Vehicle::getPrice() * getWage();
}
