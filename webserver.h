#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class WebServer {
public:
    WebServer();
    WebServer(int id);
    Request request;
    bool isBusy;
    void assignRequest(Request r);
    void runOneCycle();
    int id;
};

#endif