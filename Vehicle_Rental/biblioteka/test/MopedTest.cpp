#include "model/Moped.h"
#include <boost/test/unit_test.hpp>
using namespace std;
BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(MopedPriceCase)
        {
        Moped skuter(450, "WZ 316", 900);
            BOOST_REQUIRE_EQUAL(skuter.getPrice(),450);
        }

BOOST_AUTO_TEST_CASE(MopedRegistrationNumberCase)
        {
        Moped skuter(450, "WZ 316", 900);
        BOOST_REQUIRE_EQUAL(skuter.getRegistrationNumber(), "WZ 316");
        }

BOOST_AUTO_TEST_CASE(MopedEngineDisplacementCase)
        {
        Moped skuter(450, "WZ 316", 900);
        BOOST_REQUIRE_EQUAL(skuter.getEngineDisplacement(), 900);
        }


BOOST_AUTO_TEST_SUITE_END()
