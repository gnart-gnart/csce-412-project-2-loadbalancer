#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H
#include <queue>
#include <vector>
#include "request.h"
#include "webserver.h"

class LoadBalancer {
private:
    std::vector<WebServer> webServers;
    std::queue<Request> requestQueue;
    
public:
    LoadBalancer();
    void runOneCycle();
};


#endif