#include "model/ExceptionClientRepository.h"

ExceptionClientRepository::ExceptionClientRepository(const string &argument) : logic_error(argument){
}
const string ExceptionClientRepository::exceptionClientNotExist = "Client does not exist";
const string ExceptionClientRepository::exceptionClientNullPtr = "Null ptr";
const string ExceptionClientRepository::exceptionClientExist = "This Client already exist";