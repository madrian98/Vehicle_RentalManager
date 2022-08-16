#ifndef carClass
#define carClass
#include <string>
#include <iostream>
#include "model/MotorVehicle.h"
class Car : public MotorVehicle {
private:
    char segment;
    float getWage() const;
public:
    Car(float price, std::string registrationNumber, float engineDisplacement, char seg);
    float getPrice() override;
    std::string vehicleInfo() override;
};

#endif
