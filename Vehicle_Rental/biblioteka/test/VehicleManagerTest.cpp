
#include <boost/test/unit_test.hpp>
#include <model/Moped.h>
#include "model/Vehicle.h"
#include "model/VehicleManager.h"
#include "model/ExceptionVehicleRepository.h"
BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleManagerCreateVehicle)
    {
        VehicleManager vm;
        VehiclePtr vehicle = make_shared<Moped>(100,"ABC",50);
        VehiclePtr vehicle2 = make_shared<Moped>(500,"BCA",50);
        VehiclePtr vehicle3 = make_shared<Moped>(500,"CBA",50);
        VehiclePtr vehicle4 = make_shared<Moped>(500,"DCA",50);
        vm.addVehicle(vehicle);
        vm.addVehicle(vehicle3);
        vm.addVehicle(vehicle4);
        BOOST_REQUIRE_EQUAL( vm.getCurrentVehiclesNumber(), 3);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerDeleteVehicle)
    {
        VehicleManager vm;
        VehiclePtr vehicle = make_shared<Moped>(100,"ABC",50);
        VehiclePtr vehicle2 = make_shared<Moped>(300,"BCA",50);
        VehiclePtr vehicle3 = make_shared<Moped>(500,"CBA",50);
        VehiclePtr vehicle4 = make_shared<Moped>(500,"DCA",50);
        vm.addVehicle(vehicle);
        vm.addVehicle(vehicle2);
        vm.addVehicle(vehicle3);
        BOOST_REQUIRE_EQUAL(vm.getCurrentVehiclesNumber(), 3);
        vm.removeVehicle(vehicle2);
        vm.removeVehicle(vehicle3);
        vm.addVehicle(vehicle4);
        BOOST_REQUIRE_EQUAL( vm.getCurrentVehiclesNumber(), 2);
        BOOST_REQUIRE_EQUAL(vm.getArchVehiclesNumber(), 2);
    }

BOOST_AUTO_TEST_SUITE_END()