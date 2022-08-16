#include <iostream>
#include <string>
#include <model/Address.h>
#include <sstream>

using namespace std;

Address::Address(string ulica, int numerDomu)
{
    street = ulica;
    houseNumber = numerDomu;
}

Address::~Address()
{
}

std::string Address::getAddress() const {
    std::stringstream tekst;
    tekst <<street<<" "<<houseNumber;
    return tekst.str();
}

void Address::setAddress(std::string newStreet, int newNumber)
{
street=newStreet;
houseNumber=newNumber;
}

