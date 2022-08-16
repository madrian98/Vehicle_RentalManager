#include "model/Rent.h"
#include <iostream>

using namespace std;

Rent::Rent(ClientPtr klient, VehiclePtr pojazd)
{
    client=std::move(klient);
    vehicle=std::move(pojazd);
    timeZone = new time_zone_ptr(new posix_time_zone("CET+0"));
    ptime pt(second_clock::local_time());
    rentDateTime = new local_date_time(pt, * timeZone);
    endDateTime = nullptr;
    ID = boost::uuids::random_generator()();
    priceForDay= vehicle->getPrice() * (1-client->getDiscount());
    client -> addRent(this);
}

string Rent::rentInfo()
{
    ostringstream chain;
    chain << "Displaying loan properties"<<endl;
    chain <<"UUID: "<<ID<<endl;
    chain << "Vehicle: "<<endl<<vehicle->vehicleInfo()<<endl;
    chain <<"Client: "<<getClient()<<endl;
    chain << "Loan start date ";
    chain << (*rentDateTime).local_time()<<endl;
    if (endDateTime != nullptr)
    {
        chain << "Loan end date: ";
        chain << (*endDateTime).local_time()<<endl;
    }
    chain <<"Loan duration: "<<getPeriod();
    if(getPeriod()!=1) chain<<" dni"<<endl;
    else chain<<" day"<<endl;
    chain << "Price of loan per day: " << priceForDay << endl;
    chain<<"Final loan price: "<<getPrice()<<endl;
    return chain.str();
}
string Rent::getClient()
{
    return client->getFirstName() +" " + client->getLastName();
}

string Rent::getVehicleRented()
{
    return vehicle->vehicleInfo();
}

float Rent::getPrice()
{
    return getPeriod() * priceForDay;
}

local_date_time Rent::getRentDate()
{
    return *rentDateTime;
}

local_date_time Rent::getEndDate()
{
    return *endDateTime;
}

Rent::~Rent()
{
    delete timeZone;
    delete rentDateTime;
    delete endDateTime;
}
void Rent::endRent()
{
    ptime lt(second_clock::local_time());
    local_date_time *nowTime;
    nowTime = new local_date_time(lt, *timeZone);
    endDateTime = nowTime;
}

int Rent::getPeriod()
{
    int rentalDays;
    time_duration period;
    if(endDateTime== nullptr) {
        ptime lt(second_clock::local_time());
        local_date_time *currentTime;
        currentTime = new local_date_time(lt, *timeZone);
        period = local_time_period(*rentDateTime, *currentTime).length();
    }
    else period = local_time_period(*rentDateTime, *endDateTime).length();
    rentalDays = period.hours() / 24;
    return rentalDays + 1;
}
