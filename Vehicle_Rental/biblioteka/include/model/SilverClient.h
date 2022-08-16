#ifndef POBIPROJECT_SILVERCLIENT_H
#define POBIPROJECT_SILVERCLIENT_H

#include "model/ClientType.h"

class SilverClient : public ClientType{
public:
    int vehiclelimit() override;
    float discount() override;
    std::string getType() override;
};

#endif //POBIPROJECT_SILVERCLIENT_H
