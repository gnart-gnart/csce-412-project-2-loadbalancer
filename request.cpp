#include "request.h"

Request::Request() {
    IP_IN = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    IP_OUT = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    jobType = 'p';
    time = (rand() % 51) + 50; // random int 50-100
};