#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class WebServer {
private:
    Request request;
    
public:
    WebServer();
    bool isBusy;
    void assignRequest(Request r);
    void runOneCycle();
};

#endif