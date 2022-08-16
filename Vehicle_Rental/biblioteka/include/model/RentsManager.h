#ifndef POBIPROJECT_RENTSMANAGER_H
#define POBIPROJECT_RENTSMANAGER_H

#include <memory>
#include <string>
#include <list>
#include <vector>
#include "ClientRepository.h"
#include "RentsRepository.h"
#include "Client.h"
#include "model/SilverClient.h"
#include "model/GoldenClient.h"
#include "model/BronzeClient.h"
#include "model/ExceptionRentRepository.h"

typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<ClientRepository> ClientRepPtr;
typedef std::shared_ptr<RentsRepository> RentsRepPtr;

class RentsManager {
private:
    RentsRepPtr currentRents;
    RentsRepPtr archiveRents;
    ClientRepPtr clientRepository;
public:
    RentsManager();
    void rentVehicle(const RentPtr&);
    void returnVehicle(RentPtr);
    static std::vector<RentPtr> getAllClientRents(ClientPtr&);
    static int checkClientRentBalance(const ClientPtr&);
    void changeClientType(ClientPtr);
    std::string getCurrentRents() const;
    std::string getArchRents() const;
    int getArchRentsNumber() const;
    int getCurrentRentsNumber() const;
    std::list<RentPtr> getAllCurrentRents();
};


#endif //POBIPROJECT_RENTSMANAGER_H
