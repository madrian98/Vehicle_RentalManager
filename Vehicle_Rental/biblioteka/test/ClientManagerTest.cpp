
#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/ClientManager.h"
#include "model/ExceptionClientRepository.h"
BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerCreateClient)
    {
        ClientManager cm;
        ClientPtr client = make_shared<Client>("Jan","Nowak", "1987654321", "Polna", 1, "Polna", 215);
        ClientPtr client2 = make_shared<Client>("Jan", "Kowalski", "12345", "Polna", 215, "Polna", 2);
        cm.addClient(client);
        cm.addClient(client2);
        BOOST_REQUIRE_EQUAL(cm.getCurrentClientsNumber(), 2);
    }

    BOOST_AUTO_TEST_CASE(RepositoryDeleteClient)
    {
        ClientManager cm;
        ClientPtr client = make_shared<Client>("Jan","Nowak", "1987654321", "Polna", 1, "Polna", 215);
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski", "ABC123", "Polna", 1, "Polna", 215);
        ClientPtr client3 = make_shared<Client>("Jan","Kowal", "ABC1234", "Polna", 1, "Polna", 215);
        cm.addClient(client);
        cm.addClient(client2);
        cm.addClient(client3);
        BOOST_REQUIRE_EQUAL(cm.getCurrentClientsNumber(), 3);
        cm.removeClient(client2);
        cm.removeClient(client3);
        BOOST_REQUIRE_EQUAL(cm.getCurrentClientsNumber(), 1);
        BOOST_REQUIRE_EQUAL(cm.getArchiveClientsNumber(), 2);
    }
    BOOST_AUTO_TEST_CASE(RepositoryDeleteNullClientError)
    {
        ClientPtr client = make_shared<Client>("Jan","Nowak", "1987654321", "Polna", 1, "Polna", 215);
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski", "ABC123", "Polna", 1, "Polna", 215);
        ClientPtr client3 = make_shared<Client>("Jan","Kowal", "ABC1234", "Polna", 1, "Polna", 215);
        ClientManager cm;
        cm.addClient(client2);
        BOOST_REQUIRE_THROW(cm.removeClient(client3), logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()
