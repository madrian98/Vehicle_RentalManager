#ifndef vehicleClass
#define vehicleClass
#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Vehicle{
private:
    std::string registrationNumber;
    float price;
public:
    ~Vehicle();
    virtual std::string vehicleInfo();
    virtual float getPrice();
    virtual std::string getRegistrationNumber();
    Vehicle(float cena, std::string rejestracja);
    bool isRented=false;
};
#endif
