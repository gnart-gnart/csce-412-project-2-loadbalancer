#include "loadbalancer.h"

LoadBalancer::LoadBalancer() {
    // create 10 webservers and 200 requests
    for (int i = 0; i < 10; i++) {
        webServers.push_back(WebServer());
    }
    for (int i = 0; i < 200; i++) {
        requestQueue.push(Request());
    }
}

void LoadBalancer::runOneCycle() {
    int n = webServers.size();
    for (int i = 0; i < n; i++) {
        WebServer current = webServers.at(i);
        if (current.isBusy) {
            current.runOneCycle();
        }
        else {
            if (requestQueue.empty()) {
                webServers.erase(webServers.begin() + i);
            }
            else {
                current.assignRequest(requestQueue.back());
                requestQueue.pop();
            }
        }
    }
}