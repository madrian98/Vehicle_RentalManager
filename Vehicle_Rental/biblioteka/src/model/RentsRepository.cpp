#include "model/RentsRepository.h"

using namespace std;

bool RentsRepository::create(RentPtr &rent){
    if (rent== nullptr) throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNullPtr);
    list<RentPtr>::iterator it;
    for(it = rentRepositoryList.begin(); it != rentRepositoryList.end(); ++it){
        if(rent->vehicle->getRegistrationNumber() == (*it)->vehicle->getRegistrationNumber() && rent->vehicle->isRented){
            throw ExceptionRentRepository(ExceptionRentRepository::exceptionVehicleRented);
        }
    }
    rentRepositoryList.push_back(rent);
    return true;
}
bool RentsRepository::remove(RentPtr &rent){
    if (rent == nullptr) throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNullPtr);
    bool found = (std::find(rentRepositoryList.begin(), rentRepositoryList.end(), rent) != rentRepositoryList.end());
    if (!found){
        throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNotExist);
    }
    rentRepositoryList.remove(rent);
    return true;
}
bool RentsRepository::update(RentPtr &actualRent, RentPtr &newRent) {
    if (actualRent == nullptr || newRent == nullptr) throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNullPtr);
    auto it = std::find(rentRepositoryList.begin(), rentRepositoryList.end(), actualRent);
    it->get();
    return actualRent != nullptr && newRent == nullptr;
}
string RentsRepository::getAll() {
    ostringstream chain;
    int it=1;
    for(const auto& rentPtr : rentRepositoryList){
        chain<<"L.p. "<<to_string(it++)<<endl;
        chain<< rentPtr->rentInfo();
        chain<<endl;
    }
    return chain.str();
}
RentPtr& RentsRepository::find(const unsigned int& in) {
    if (in > rentRepositoryList.size()) throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNotExist);
    unsigned int i=1;
    for(auto& c : rentRepositoryList){
        if(i==in){
            return c;
        }
        i++;
    }
    throw ExceptionRentRepository(ExceptionRentRepository::exceptionRentNotExist);
}

const list<RentPtr>& RentsRepository::getRepository() const{
    return rentRepositoryList;
}