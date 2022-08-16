#include "model/BronzeClient.h"

int BronzeClient::vehiclelimit() {
    return 2;
}

float BronzeClient::discount() {
    return 0.15;
}

std::string BronzeClient::getType() {
    return "Bronze client";
}