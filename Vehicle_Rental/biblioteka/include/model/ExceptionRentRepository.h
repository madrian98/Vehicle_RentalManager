#ifndef POBIPROJECT_EXCEPTIONRENTREPOSITORY_H
#define POBIPROJECT_EXCEPTIONRENTREPOSITORY_H

#include <stdexcept>

using  namespace std;

class ExceptionRentRepository : public logic_error {
public:
    explicit ExceptionRentRepository(const string &);
    static const string exceptionVehicleRented;
    static const string exceptionRentNotExist;
    static const string exceptionLimitExceeded;
    static const string exceptionRentNullPtr;
};

#endif //POBIPROJECT_EXCEPTIONRENTREPOSITORY_H
