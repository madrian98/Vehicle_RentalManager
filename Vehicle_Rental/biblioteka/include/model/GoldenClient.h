
#ifndef POBIPROJECT_GOLDENCLIENT_H
#define POBIPROJECT_GOLDENCLIENT_H

#include "model/ClientType.h"

class GoldenClient : public ClientType{
public:
    int vehiclelimit() override;
    float discount() override;
    std::string getType() override;
};


#endif //POBIPROJECT_GOLDENCLIENT_H
