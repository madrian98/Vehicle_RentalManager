#include "model/Bicycle.h"
#include <string>
#include <utility>

using namespace std;

Bicycle::Bicycle(float cena, string nrRejestracja)
        : Vehicle(cena, std::move(nrRejestracja)){}

string Bicycle::vehicleInfo(){
    std::string chain;
    chain = "Bike: " + Vehicle::vehicleInfo();
    return chain;
}

float Bicycle::getPrice(){
    return Vehicle::getPrice();
}

