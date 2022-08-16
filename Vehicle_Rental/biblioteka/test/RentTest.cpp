#include <boost/test/unit_test.hpp>
#include "model/Rent.h"


using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)


    BOOST_AUTO_TEST_CASE(RentingVehicle)
    {
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "123456", "Polna", 11, "Polna", 215);
        VehiclePtr pojazd = make_shared<Vehicle>(1500, "ABC123");
        Rent renting(client,pojazd);
        BOOST_REQUIRE_EQUAL(renting.getVehicleRented(),pojazd->vehicleInfo());
    }

BOOST_AUTO_TEST_SUITE_END()
