#include "model/Car.h"
#include <boost/test/unit_test.hpp>
using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(CarPriceCase)
        {
        Car Mercedes(1200, "WX 311", 1600, 'B');
        BOOST_REQUIRE_EQUAL(Mercedes.getPrice(), 1716);
        }

BOOST_AUTO_TEST_CASE(CarRegistrationNumberCase)
        {
        Car Mercedes(1200, "WX 311", 1600, 'B');
        BOOST_REQUIRE_EQUAL(Mercedes.getRegistrationNumber(), "WX 311");
        }

BOOST_AUTO_TEST_CASE(CarEngineDisplacementCase)
        {
        Car Mercedes(1200, "WX 311", 1600, 'B');
        BOOST_REQUIRE_EQUAL(Mercedes.getEngineDisplacement(), 1600);
        }




BOOST_AUTO_TEST_SUITE_END()
