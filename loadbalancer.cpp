#include "loadbalancer.h"


void LoadBalancer::createWebservers(int num_web_servers) {
    for (int i = 0; i < num_web_servers; i++) {
        webServers.push_back(WebServer());
        for (int j = 0; j < 5; j++) {
            requestQueue.push(Request());
        }
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