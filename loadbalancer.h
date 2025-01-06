#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H
#include <queue>
#include <vector>
#include <string.h>
#include "request.h"
#include "webserver.h"

class LoadBalancer {
private:
    std::vector<WebServer> webServers;
    std::queue<Request> requestQueue;
    std::queue<int> availableWebServerIds;
    bool verboseLogging; // Added: Logging mode

public:
    LoadBalancer();
    void runOneCycle(std::string time);
    void createWebservers(int num_web_servers);
    void pushNewRequest();

    int getServersLeft();
    int getRequestsLeft();

    void setVerboseLogging(bool verbose); // Added: Set logging mode

    int servers_created = 0;
    int servers_deleted = 0;
    int requests_finished = 0;
};

#endif