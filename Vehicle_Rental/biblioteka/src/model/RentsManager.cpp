#include "model/RentsManager.h"

using namespace std;

RentsManager::RentsManager():
    currentRents(new RentsRepository),
    archiveRents(new RentsRepository)
{}

void RentsManager::rentVehicle(const RentPtr& r) {
    bool found = (find(currentRents->getRepository().begin(),currentRents->getRepository().end(),r) != currentRents ->getRepository().end());
    if (found) throw ExceptionRentRepository(ExceptionRentRepository::exceptionVehicleRented);
    bool isRented = false;
    for(const auto& rent : currentRents->getRepository())
    {
        if(r->vehicle->getRegistrationNumber() == rent->vehicle->getRegistrationNumber())
        {
            isRented = true;
            break;
        }
    }
    if(!isRented and r -> client -> getNumberofRents() < r -> client -> getVehicleLimit())
    {
        currentRents -> create(const_cast<RentPtr &>(r));
        r -> client -> addCurrentRent(r);
        r->vehicle->isRented=true;
    }
    else
    {
        if(!isRented)
        {
           throw ExceptionRentRepository(ExceptionRentRepository::exceptionLimitExceeded);
        }
        else
        {
            throw ExceptionRentRepository(ExceptionRentRepository::exceptionVehicleRented);
        }
    }
}

void RentsManager::returnVehicle(RentPtr r) {
    if(r== nullptr) throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNullPtr);
    r->client->removeArchiveRent(r);
    r->endRent();
    currentRents->remove(r);
    r->vehicle->isRented=false;
    archiveRents->create(r);
    r->client->setBalance(r);
    changeClientType(static_cast<ClientPtr>(r->client));
}

vector<RentPtr> RentsManager::getAllClientRents(ClientPtr& klient) {
    return klient->getAllClientRents();
}

int RentsManager::checkClientRentBalance(const ClientPtr& klient) {
    return klient->getBalance();
}

void RentsManager::changeClientType(ClientPtr klient) {
        int b=checkClientRentBalance(klient);
        if(b>=1000 && b<3000){
            ClientTypePtr bronze= make_shared<BronzeClient>();
            clientRepository->changeType(klient,bronze);
        }
        else if(b>=3000 and b<10000){
            ClientTypePtr silver= make_shared<SilverClient>();
            clientRepository->changeType(klient,silver);
        }
        else if(b>=10000){
            ClientTypePtr gold= make_shared<GoldenClient>();
            clientRepository->changeType(klient,gold);
        }
 //   }
}

int RentsManager::getArchRentsNumber() const {
    return archiveRents->getRepository().size();
}

int RentsManager::getCurrentRentsNumber() const {
    return currentRents->getRepository().size();
}

string RentsManager::getArchRents() const {
    return archiveRents->getAll();
}

string RentsManager::getCurrentRents() const {
    return currentRents->getAll();
}

std::list<RentPtr> RentsManager::getAllCurrentRents() {
    return currentRents->getRepository();
}
