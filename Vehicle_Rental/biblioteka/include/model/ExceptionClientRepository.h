#ifndef POBIPROJECT_EXCEPTIONCLIENTREPOSITORY_H
#define POBIPROJECT_EXCEPTIONCLIENTREPOSITORY_H

#include <stdexcept>

using namespace std;

class ExceptionClientRepository : public logic_error {
public:
    explicit ExceptionClientRepository(const string&);
    static const string exceptionClientNotExist;
    static const string exceptionClientNullPtr;
    static const string exceptionClientExist;
};


#endif //POBIPROJECT_EXCEPTIONCLIENTREPOSITORY_H
