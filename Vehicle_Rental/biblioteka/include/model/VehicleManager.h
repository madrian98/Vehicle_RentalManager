#ifndef POBIPROJECT_VEHICLEMANAGER_H
#define POBIPROJECT_VEHICLEMANAGER_H
#include <memory>
#include <string>
#include <list>
#include "Vehicle.h"
#include "VehicleRepository.h"



typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepPtr;

class VehicleManager {
private:
    VehicleRepPtr currentVehicles;
    VehicleRepPtr archiveVehicles;
public:
    void addVehicle(VehiclePtr &);
    void removeVehicle(VehiclePtr &);
    VehicleManager();
    std::string getArchVehicles() const;
    std::string getCurrentVehicles() const;
    int getArchVehiclesNumber() const;
    int getCurrentVehiclesNumber() const;
    list<VehiclePtr> getAllCurrentVehicles();
};

#endif //POBIPROJECT_VEHICLEMANAGER_H