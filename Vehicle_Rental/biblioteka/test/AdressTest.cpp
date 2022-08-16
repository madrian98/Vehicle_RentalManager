
#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include "model/Address.h"



BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)


    BOOST_AUTO_TEST_CASE(AdressGetter)
    {
        Address adres("Polna", 215);
        BOOST_REQUIRE_EQUAL(adres.getAddress(), "Polna 215");
    }

    BOOST_AUTO_TEST_CASE(AddressSetter)
    {
        Address adres("Polna", 215);
        adres.setAddress("Polna", 1);
        BOOST_REQUIRE_EQUAL(adres.getAddress(), "Polna 1");
    }
    BOOST_AUTO_TEST_CASE(AddressClient)
    {
        Address adres("Polna", 215);
        Client klient1("Jan", "Nowak", "98765", "Polna", 215, "Polna", 1);
        Client klient2("Jan", "Kowalski", "43210", "Polna", 215, "Polna", 1);
        adres.setAddress("Polna", 2);
        BOOST_REQUIRE_EQUAL(klient1.getAddress(), klient2.getAddress());
    }



BOOST_AUTO_TEST_SUITE_END()


