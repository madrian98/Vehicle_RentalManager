#ifndef clientClass
#define clientClass
#include <string>
#include "model/Address.h"
#include "model/Rent.h"
#include <vector>
#include <iostream>
#include <memory>
#include <list>

using namespace std;

class Rent;
class ClientType;
typedef shared_ptr<ClientType> ClientTypePtr;
typedef shared_ptr<Address> AddAddressPtr;
typedef shared_ptr<Rent> RentPtr;

class Client{

private:
    string firstName;
    string lastName;
    string personalID;
    Address *newAddress;
    Address *registeredAddress;
    vector<Rent *> rentVector{};
    list<RentPtr> currentRents{};
    ClientTypePtr clientType;
    vector<RentPtr> archivedRents{};
    int balance{};

public:

    Client(std::string firstname,
           std::string lastname,
           std::string id,
           std::string ulica,
           int nrdomu,
           std::string ulica2,
           int nrdomu2);
    virtual ~Client();
    std::string clientInfo();
    void setLastName(std::string newLastName);
    void setAddress(string,int);
    void setRegisteredAddress(string,int);
    std::string getFirstName();
    std::string getLastName();
    std::string getPersonalID();
    std::string getAddress();
    std::string getRegisteredAddress();
    void addRent(Rent *r);
    void allRents();
    void setClientType(const ClientTypePtr&);
    int getNumberofRents();
    int getVehicleLimit();
    void addCurrentRent(const RentPtr&);
    void archiveRent(const RentPtr&);
    void setBalance(const RentPtr&);
    void removeArchiveRent(const RentPtr&);
    float getDiscount();
    vector<RentPtr> getAllClientRents();
    int getBalance() const;
    std::string getClientType();
};

typedef shared_ptr<Client> ClientPtr;
#endif

