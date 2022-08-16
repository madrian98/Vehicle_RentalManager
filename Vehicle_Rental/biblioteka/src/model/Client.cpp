#include <iostream>
#include <string>
#include <utility>
#include "model/Client.h"
#include <vector>
#include "model/Rent.h"
#include "model/ClientType.h"

Client::Client(string firstname, string lastname, string id, string ulica, int nrDomu, string ulica2, int nrDomu2)
{
    firstName = std::move(firstname);
    lastName = std::move(lastname);
    personalID = std::move(id);
    newAddress = new Address(std::move(ulica), nrDomu);
    registeredAddress = new Address(std::move(ulica2), nrDomu2);
}

Client::~Client()
{
    delete newAddress;
    delete registeredAddress;
}

string Client::clientInfo(){
    ostringstream chain;
    chain << "Displaying client info" <<endl;
    chain << "Full name: " << firstName + " " + lastName <<endl;
    chain << "ID: " << personalID <<endl;;
    chain << "Address: " <<newAddress->getAddress()<< endl;
    chain << "Registered address: " <<registeredAddress->getAddress()<< endl;
    chain << "Client type: "<<getClientType()<<endl;
    chain << "Client balance: "<<getBalance()<<endl;
    return chain.str();
}

std::string Client::getFirstName() {
        return firstName;
}

std::string Client::getLastName() {
        return lastName;
}

std::string Client::getPersonalID() {
        return personalID;
}

void Client::setLastName(std::string newLastname) {
        lastName = std::move(newLastname);
}

string Client::getAddress()
{
        return newAddress-> getAddress();
}

string Client::getRegisteredAddress()
{
        return registeredAddress -> getAddress();
}


void Client::setAddress(std::string street,int number) {
    newAddress->setAddress(std::move(street), number);
}

void Client::setRegisteredAddress(std::string street,int number) {
    registeredAddress->setAddress(std::move(street), number);
}

void Client::addRent(Rent *r) {
    rentVector.push_back(r);
}

void Client::allRents()
{
    for (auto & i : rentVector) {
        i->rentInfo();
        cout << endl;
    }
}

void Client::setClientType(const ClientTypePtr& type)
{
    clientType=ClientTypePtr(type);
}

int Client::getNumberofRents() {
    return currentRents.size();
}

int Client::getVehicleLimit() {
    if(clientType== nullptr){
        return 1;
    }
    return clientType->vehiclelimit();
}

void Client::addCurrentRent(const RentPtr& r) {
    currentRents.push_back(r);
}

void Client::archiveRent(const RentPtr& r) {
    archivedRents.push_back(r);
}

void Client::setBalance(const RentPtr& r) {
    balance+= r->getPrice();
}

void Client::removeArchiveRent(const RentPtr& r) {
    currentRents.remove(r);
    archiveRent(r);
}

float Client::getDiscount() {
    if(clientType== nullptr){
        return 0;
    }
    return clientType->discount();
}

vector<RentPtr> Client::getAllClientRents() {
    vector<RentPtr> v{begin(archivedRents), end(archivedRents)};
    return v;
}

int Client::getBalance() const {
    return balance;
}

std::string Client::getClientType() {
    if(clientType== nullptr) return "Null";
    return clientType->getType();
}
