#include <iostream>
#include <string>
#include "model/VehicleRepository.h"

using namespace std;

bool VehicleRepository::create(VehiclePtr &vehicle) {
    if (vehicle== nullptr) throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleNullPtr);
    list<VehiclePtr>::iterator it;
    for(it = vehicleRepository.begin(); it != vehicleRepository.end(); ++it){
        if(vehicle->getRegistrationNumber() == (*it)->getRegistrationNumber()){
            throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleExist);
        }
    }
    vehicleRepository.push_back(vehicle);
    return true;
}

bool VehicleRepository::remove(VehiclePtr &vehicle) {
    if (vehicle == nullptr) throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleNullPtr);
    bool found=(std::find(vehicleRepository.begin(),vehicleRepository.end(),vehicle)!=vehicleRepository.end());
    if (!found){
         throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleNotExist);
    }
    vehicleRepository.remove(vehicle);
    return true;
}

bool VehicleRepository::update(VehiclePtr &actualVehicle, VehiclePtr &newVehicle) {
    if (actualVehicle == nullptr || newVehicle == nullptr) throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleNullPtr);
    actualVehicle=newVehicle;
    vehicleRepository.erase(std::remove(vehicleRepository.begin(),vehicleRepository.end(),newVehicle),vehicleRepository.end());
    return actualVehicle != nullptr && newVehicle == nullptr;
}

string VehicleRepository::getAll() {
    ostringstream chain;
    int it=1;
    for(const auto& vehiclePtr: vehicleRepository){
        chain<<"L.p. "<<to_string(it++)<<endl;
        chain<< vehiclePtr->vehicleInfo();
        chain<<endl;
    }
    return chain.str();
}

VehiclePtr &VehicleRepository::find(const unsigned int & in) {
    if (in > vehicleRepository.size()) throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleNotExist);
    unsigned int i=1;
    for(auto& c : vehicleRepository){
        if(i==in){
            return c;
        }
        i++;
    }
    throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleNotExist);
}

const list<VehiclePtr>& VehicleRepository::getRepository() const{
    return vehicleRepository;
}
