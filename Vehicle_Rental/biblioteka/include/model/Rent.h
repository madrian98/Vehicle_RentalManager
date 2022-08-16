#include <climits>

#ifndef rentClass
#define rentClass
#include <string>
#include <memory>
#include "model/Vehicle.h"
#include "model/Client.h"
#include "Client.h"
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

typedef shared_ptr<Vehicle> VehiclePtr;
class Client;
typedef shared_ptr<Client> ClientPtr;

class Rent {
private:
    uuid ID;

    local_date_time *rentDateTime;

    local_date_time *endDateTime;

    ClientPtr client;
    VehiclePtr vehicle;

    time_zone_ptr *timeZone;

    friend class RentsManager;
    friend class RentsRepository;

    float priceForDay;

public:
    Rent(ClientPtr klient, VehiclePtr pojazd);
    local_date_time getRentDate();
    local_date_time getEndDate();
    std::string rentInfo();
    void endRent();
    int getPeriod();
    float getPrice();
    std::string getClient();
    std::string getVehicleRented();
    ~Rent();
};
typedef shared_ptr<Rent> RentPtr;
#endif
