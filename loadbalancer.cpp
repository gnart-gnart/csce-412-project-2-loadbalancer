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
    for (int i = 0; i < webServers.size(); i++) {
        WebServer current = webServers.at(i);
        current.runOneCycle();
        if (!current.isBusy) {
            if (requestQueue.empty()) {
                webServers.erase(webServers.begin() + i);
                i--;
            }
            else {
                current.assignRequest(requestQueue.back());
                requestQueue.pop();
            }
        }
    }
}