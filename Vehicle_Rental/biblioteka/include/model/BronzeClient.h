#ifndef POBIPROJECT_BRONZECLIENT_H
#define POBIPROJECT_BRONZECLIENT_H

#include "model/ClientType.h"

class BronzeClient : public ClientType{
public:
    int vehiclelimit() override;
    float discount() override;
    std::string getType() override;
};

#endif //POBIPROJECT_BRONZECLIENT_H
