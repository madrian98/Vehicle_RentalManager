cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES
        src/model/Client.cpp
        src/model/Address.cpp
        src/model/Vehicle.cpp
        src/model/Rent.cpp
        src/model/MotorVehicle.cpp
        src/model/Car.cpp
        src/model/Moped.cpp
        src/model/Bicycle.cpp
        src/model/RentsRepository.cpp
        src/model/VehicleRepository.cpp
        include/model/ClientType.h src/model/GoldenClient.cpp include/model/GoldenClient.h src/model/SilverClient.cpp include/model/SilverClient.h src/model/BronzeClient.cpp include/model/BronzeClient.h src/model/ClientRepository.cpp include/model/ClientRepository.h src/model/RentsManager.cpp include/model/RentsManager.h src/model/ExceptionClientRepository.cpp include/model/ExceptionClientRepository.h src/model/ExceptionRentRepository.cpp include/model/ExceptionRentRepository.h include/model/Repository.h src/model/VehicleManager.cpp include/model/VehicleManager.h src/model/ClientManager.cpp include/model/ClientManager.h src/model/ExceptionVehicleRepository.cpp include/model/ExceptionVehicleRepository.h src/model/Functions.cpp include/model/Functions.h)
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)
enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/AdressTest.cpp
        test/BicycleTest.cpp
        test/master.cpp
        test/CarTest.cpp
        test/MopedTest.cpp
        test/ClientTest.cpp
        test/VehicleManagerTest.cpp
        test/ClientManagerTest.cpp
        test/VehicleRepositoryTest.cpp
        test/RentTest.cpp
        test/RentsRepositoryTest.cpp
        )

add_executable (TestBibl ${SOURCE_TEST_FILES})


target_link_libraries (TestBibl
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )


add_test(TestBiblioteki1 TestBibl
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
