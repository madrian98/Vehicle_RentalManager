
#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "model/BronzeClient.h"
#include "model/SilverClient.h"
#include "model/GoldenClient.h"
BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientFirstNameCase)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        BOOST_REQUIRE_EQUAL(client.getFirstName(), "Jan");
    }

    BOOST_AUTO_TEST_CASE(ClientLastNameCase)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        BOOST_REQUIRE_EQUAL(client.getLastName(), "Kowalski");
    }

    BOOST_AUTO_TEST_CASE(ClientPersonalIDCase)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        BOOST_CHECK_EQUAL(client.getPersonalID(), "12345");
    }

    BOOST_AUTO_TEST_CASE(ClientAddressCase)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        BOOST_CHECK_EQUAL(client.getAddress(), "Polna 215");
    }

    BOOST_AUTO_TEST_CASE(ClientRegisteredAdressCase)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        BOOST_CHECK_EQUAL(client.getRegisteredAddress(), "Polna 2");
    }
    BOOST_AUTO_TEST_CASE(SetNewAddress)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        client.setAddress("Lesna", 15);
        BOOST_CHECK_EQUAL(client.getAddress(), "Lesna 15");
    }
    BOOST_AUTO_TEST_CASE(ClientSetNewRegisteredAddress)
    {
        Client client("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        client.setRegisteredAddress("Polna", 25);
        BOOST_CHECK_EQUAL(client.getRegisteredAddress(), "Polna 25");
    }
    BOOST_AUTO_TEST_CASE(ClientGetDefaultLimit)
    {
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 1);
    }
    BOOST_AUTO_TEST_CASE(ClientGetBronzeLimit)
    {
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        ClientTypePtr clienttype(new BronzeClient);
        (*client).setClientType(clienttype);
        BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 2);
    }
    BOOST_AUTO_TEST_CASE(ClientGetSilverLimit)
    {
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        ClientTypePtr clienttype(new SilverClient);
        (*client).setClientType(clienttype);
        BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 5);
    }
    BOOST_AUTO_TEST_CASE(ClientGetGoldenLimit)
    {
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        ClientTypePtr clienttype(new GoldenClient);
        (*client).setClientType(clienttype);
        BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 10);
    }





BOOST_AUTO_TEST_SUITE_END()
