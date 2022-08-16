#ifndef POBIPROJECT_EXCEPTIONVEHICLEREPOSITORY_H
#define POBIPROJECT_EXCEPTIONVEHICLEREPOSITORY_H

#include <stdexcept>

using namespace std;

class ExceptionVehicleRepository : public logic_error {
public:
    explicit ExceptionVehicleRepository(const string&);
    static const string exceptionVehicleNotExist;
    static const string exceptionVehicleNullPtr;
    static const string exceptionVehicleExist;
};


#endif //POBIPROJECT_EXCEPTIONVEHICLEREPOSITORY_H
