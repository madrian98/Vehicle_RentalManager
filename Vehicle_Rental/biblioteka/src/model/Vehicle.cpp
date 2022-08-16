#include <string>
#include "model/Vehicle.h"

using namespace std;

Vehicle::Vehicle(float cena,std::string rejestracja){
    price = cena;
    registrationNumber = std::move(rejestracja);
}

Vehicle::~Vehicle(){}

string Vehicle::vehicleInfo(){
    string info;
    info = "Registration number: " + registrationNumber + " Price: " + to_string(price);
    return info;
}

float Vehicle::getPrice(){
    return price;
}

std::string Vehicle::getRegistrationNumber(){
    return registrationNumber;
}
