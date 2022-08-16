#ifndef mopedClass
#define mopedClass
#include <string>
#include <iostream>
#include "model/MotorVehicle.h"

class Moped : public MotorVehicle{
public:
    Moped(float price, std::string registrationNumber, float engineDisplacement);
    std::string vehicleInfo() override;
};
#endif