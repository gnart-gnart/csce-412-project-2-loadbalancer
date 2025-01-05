#ifndef REQUEST_H
#define REQUEST_H

#include <string>

struct Request {
    std::string IP_IN, IP_OUT;
    int timeLeft;
    char jobType;
};

#endif