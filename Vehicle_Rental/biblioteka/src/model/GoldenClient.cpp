
#include "model/GoldenClient.h"

int GoldenClient::vehiclelimit() {
    return 10;
}

float GoldenClient::discount() {
    return 0.5;
}

std::string GoldenClient::getType() {
    return "Gold client";
}