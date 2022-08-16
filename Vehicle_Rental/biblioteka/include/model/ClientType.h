#ifndef POBIPROJECT_CLIENTTYPE_H
#define POBIPROJECT_CLIENTTYPE_H

#include <string>

class ClientType{
public:
    virtual int vehiclelimit()= 0;
    virtual float discount()= 0;
    virtual ~ClientType()=default;
    virtual std::string getType()=0;
};

#endif //POBIPROJECT_CLIENTTYPE_H
