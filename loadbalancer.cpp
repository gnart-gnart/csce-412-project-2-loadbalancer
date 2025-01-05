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

}