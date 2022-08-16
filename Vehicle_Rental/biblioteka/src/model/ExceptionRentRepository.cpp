
#include "model/ExceptionRentRepository.h"

ExceptionRentRepository::ExceptionRentRepository(const string &argument) : logic_error(argument){
}
const string ExceptionRentRepository::exceptionVehicleRented = "Vehicle already rented";
const string ExceptionRentRepository::exceptionLimitExceeded = "Client exceeded limit";
const string ExceptionRentRepository::exceptionRentNotExist = "This rent does not exist";
const string ExceptionRentRepository::exceptionRentNullPtr = "Invalid rent (nullptr)";

