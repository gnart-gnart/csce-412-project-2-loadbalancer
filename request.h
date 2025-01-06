#ifndef REQUEST_H
#define REQUEST_H

#include <string>

struct Request {
    Request();
    Request(int id);
    std::string IP_IN, IP_OUT;
    int timeLeft, id;
    char jobType;
};

#endif