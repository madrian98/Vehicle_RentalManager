#include "model/ClientManager.h"
#include "model/VehicleManager.h"
#include "model/RentsManager.h"
#include "model/ExceptionClientRepository.h"
#include "model/ExceptionVehicleRepository.h"
#include "model/ExceptionRentRepository.h"
#include "model/Car.h"
#include "Moped.h"
#include "Bicycle.h"

#ifndef POBIPROJECT_FUNCTIONS_H
#define POBIPROJECT_FUNCTIONS_H


namespace Functions {
    void displayFunction(const ClientManager& clientManager, const VehicleManager& vehicleManager, const RentsManager& rentsManager);
    void manageFunction(ClientManager& clientManager, VehicleManager& vehicleManager, RentsManager& rentsManager);
    void dodajKlienta(ClientManager& clientManager);
    void usunKlienta(ClientManager& clientManger);
    void dodajPojazd(VehicleManager& vehicleManager);
    void usunPojazd(VehicleManager& vehicleManager);
    void dodajWypozyczenie(ClientManager& clientManager, VehicleManager& vehicleManager, RentsManager& rentsManager);
    void zakonczWypozyczenie(VehicleManager& vehicleManager, RentsManager& rentsManager);
};


#endif //POBIPROJECT_FUNCTIONS_H
