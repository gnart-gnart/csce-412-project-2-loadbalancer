#include "request.h"

/**
 * @brief Constructs a Request object with default values.
 */
Request::Request() {
    IP_IN = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    IP_OUT = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    jobType = 'p';
    timeLeft = (rand() % 91) + 10; // random int 10-100
    this->id = -1;
}

/**
 * @brief Constructs a Request object with a specified ID.
 * @param id The unique ID of the request.
 */
Request::Request(int id) {
    IP_IN = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    IP_OUT = std::to_string(rand() % 256) + "." + std::to_string(rand() % 256) + "."
         + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256);
    jobType = 'p';
    timeLeft = (rand() % 51) + 50; // random int 50-100
    this->id = id;
}