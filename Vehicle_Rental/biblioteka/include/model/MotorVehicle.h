#ifndef motorVehicleClass
#define motorVehicleClass
#include <string>
#include <iostream>
#include "Vehicle.h"

class MotorVehicle : public Vehicle{
private:
    float engineDisplacement;
    float getWage() const;
public:
    MotorVehicle(float price, std::string registrationNumber, float engineCapacity);
    virtual ~MotorVehicle();
    float getEngineDisplacement() const;
    float getPrice() override;
    std::string vehicleInfo() override;
};
#endif