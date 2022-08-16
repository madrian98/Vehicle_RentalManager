#ifndef bicycleClass
#define bicycleClass
#include <string>
#include <iostream>
#include "model/Vehicle.h"

class Bicycle : public Vehicle
{
public:
    Bicycle(float price, std::string registrationNumber);
    float getPrice() override;
    std::string vehicleInfo() override;
};

#endif
