#include "model/ExceptionVehicleRepository.h"

ExceptionVehicleRepository::ExceptionVehicleRepository(const string &argument) : logic_error(argument){
}
const string ExceptionVehicleRepository::exceptionVehicleNotExist = "Vehicle does not exist";
const string ExceptionVehicleRepository::exceptionVehicleNullPtr = "Null ptr";
const string ExceptionVehicleRepository::exceptionVehicleExist = "This Vehicle already exist";