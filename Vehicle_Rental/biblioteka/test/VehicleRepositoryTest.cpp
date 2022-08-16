
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "model/VehicleRepository.h"
#include "model/Bicycle.h"
#include "model/Car.h"
#include "model/Moped.h"



BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryVehicle)
    {
        VehiclePtr veh[8];
        veh[0] = make_shared<Bicycle>(150, "AB123");
        veh[1] = make_shared<Bicycle>(120, "CD321");
        veh[2] = make_shared<Moped>(450, "WZ 316", 900);
        veh[3] = make_shared<Moped>(350, "WZ 310", 400);
        veh[4] = make_shared<Car>(2000,"WX 310", 1300, 'A');
        veh[5] = make_shared<Car>(1250, "WX 311", 1600, 'B');
        veh[6] = make_shared<Car>(900, "WX 31", 2000, 'C');
        veh[7] = make_shared<Car>(4500, "WX 314", 3500, 'E');
        VehicleRepository rep;
        ostringstream tekst;
        for(unsigned int i = 0; i<8; i++)
        {
            rep.create(veh[i]);
            if(i==3)
            {
                tekst << veh[i]->vehicleInfo();
            }
        }
        BOOST_REQUIRE_EQUAL(rep.find(2), veh[1]);
    }

BOOST_AUTO_TEST_SUITE_END()

