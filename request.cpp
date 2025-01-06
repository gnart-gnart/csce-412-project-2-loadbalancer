#include "request.h"

Request::Request() {
    IP_IN = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    IP_OUT = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    jobType = 'p';
    timeLeft = (rand() % 51) + 50; // random int 50-100
    this->id = -1;
};

Request::Request(int id) {
    IP_IN = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    IP_OUT = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    jobType = 'p';
    timeLeft = (rand() % 51) + 50; // random int 50-100
    this->id = id;
};