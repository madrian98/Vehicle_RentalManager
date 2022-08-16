#include "model/Bicycle.h"
#include <boost/test/unit_test.hpp>
using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(BicyclePriceCase)
        {
        Bicycle bike(120, "CD321");
        BOOST_REQUIRE_EQUAL(bike.getPrice(), 120);
        }

BOOST_AUTO_TEST_CASE(BicycleRegistrationNumberCase)
        {
        Bicycle bike(120, "CD321");
        BOOST_REQUIRE_EQUAL(bike.getRegistrationNumber(), "CD321");
        }


BOOST_AUTO_TEST_SUITE_END()
