#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/RentsRepository.h"
#include "model/Bicycle.h"
#include "model/Rent.h"
#include <sstream>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(RepositoryCreateRent)
        {
            ostringstream tekst;
            RentsRepository repository;
            VehiclePtr FatBike = make_shared<Bicycle>(150, "ABC12");
            VehiclePtr FatBike2 = make_shared<Bicycle>(150, "ABC34");
            ClientPtr client1 = make_shared<Client>("Jan","Nowak", "1987654321", "Polna", 1, "Polna", 215);
            ClientPtr client2 = make_shared<Client>("Jan","Kowalski", "ABC123", "Polna", 1, "Polna", 215);
            RentPtr r = make_shared<Rent>(client1, FatBike);
            repository.create(r);
            RentPtr r2 = make_shared<Rent>(client2, FatBike2);
            tekst<<"L.p. 1"<<endl;
            tekst<< r->rentInfo();
            tekst<<endl<<"L.p. 2"<<endl;
            tekst<< r2->rentInfo()<<endl;
            repository.create(r2);
            BOOST_REQUIRE_EQUAL(repository.getAll(), tekst.str());
        }

BOOST_AUTO_TEST_SUITE_END()
