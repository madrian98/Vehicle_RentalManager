#include "model/SilverClient.h"

int SilverClient::vehiclelimit() {
    return 5;
}

float SilverClient::discount() {
    return 0.3;
}

std::string SilverClient::getType() {
    return "Silver client";
}