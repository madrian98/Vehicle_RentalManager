#include <string>
#include "model/Moped.h"

using namespace std;

Moped::Moped(float price, string registrationNumber, float engineDisplacement)
        : MotorVehicle(price, std::move(registrationNumber), engineDisplacement){
}

string Moped::vehicleInfo(){
    std::string info;
    info = "Moped:" + MotorVehicle::vehicleInfo();
    return info;
}