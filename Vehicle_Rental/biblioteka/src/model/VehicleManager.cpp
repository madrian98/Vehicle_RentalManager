#include "model/VehicleManager.h"
#include"model/ExceptionVehicleRepository.h"
#include"model/VehicleRepository.h"
using namespace std;

VehicleManager::VehicleManager():
        currentVehicles(new VehicleRepository),
        archiveVehicles(new VehicleRepository)
{}

void VehicleManager::addVehicle(VehiclePtr &vehicle) {
    for(const auto& veh : currentVehicles->getRepository())
    {
        if(vehicle == veh)
        {
            throw ExceptionVehicleRepository(ExceptionVehicleRepository::exceptionVehicleExist);
        }
    }
    for(const auto& veh : archiveVehicles->getRepository())
    {
        if(vehicle == veh)
        {
            archiveVehicles->remove(const_cast<VehiclePtr &>(vehicle));
            break;
        }
    }
    currentVehicles->create(const_cast<VehiclePtr &>(vehicle));
}

void VehicleManager::removeVehicle(VehiclePtr & vehicle) {
    archiveVehicles->create(vehicle);
    currentVehicles->remove(vehicle);
}

int VehicleManager::getArchVehiclesNumber() const {
    return archiveVehicles->getRepository().size();
}

int VehicleManager::getCurrentVehiclesNumber() const {
    return currentVehicles->getRepository().size();
}

string VehicleManager::getCurrentVehicles() const {
    return currentVehicles->getAll();
}

std::string VehicleManager::getArchVehicles() const {
    return archiveVehicles->getAll();
}

list<VehiclePtr> VehicleManager::getAllCurrentVehicles() {
    return currentVehicles->getRepository();
}

