#ifndef vehicleRepositoryClass
#define vehicleRepositoryClass
#include <list>
#include <memory>
#include <algorithm>
#include "model/Vehicle.h"
#include "model/Repository.h"
#include "model/ExceptionVehicleRepository.h"

typedef shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository: public Repository<Vehicle>{
private:
    list<VehiclePtr> vehicleRepository{};
public:
    bool create(VehiclePtr &vehicle) override;
    bool remove(VehiclePtr &vehicle) override;
    bool update(VehiclePtr &actualVehicle, VehiclePtr &newVehicle) override;
    std::string getAll() override;
    VehiclePtr& find(const unsigned int &) override;
    const list<VehiclePtr>& getRepository() const override ;
};
#endif