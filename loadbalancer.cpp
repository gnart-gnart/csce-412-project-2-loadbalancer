#include "loadbalancer.h"
#include <iostream>

LoadBalancer::LoadBalancer() {

}

void LoadBalancer::createWebservers(int num_web_servers) {
    for (int i = 0; i < num_web_servers; i++) {
        webServers.push_back(WebServer(i + 1));
        for (int j = 0; j < 5; j++) {
            requestQueue.push(Request((i * 5) + j + 1));
        }
    }
    availableWebServerIds.push(webServers.size());
}

void LoadBalancer::runOneCycle() {
    for (int i = 0; i < webServers.size(); i++) {
        WebServer current = webServers.at(i);
        current.runOneCycle();
        if (!current.isBusy) {
            if (requestQueue.empty()) {
                if (webServers.size() > 3) {
                    // log that webServer finished task
                    std::cout << "WebServer " << current.id << " finished request "
                        << current.request.id << std::endl;
                    requests_finished++;

                    webServers.erase(webServers.begin() + i);
                    availableWebServerIds.push(i + 1);
                    i--;
                }
            }
            else {
                current.assignRequest(requestQueue.front());
                requestQueue.pop();
                // log that webServer assigned request
                servers_deleted++;
                std::cout << "WebServer " << current.id << " assigned Request " 
                    << requestQueue.front().id << std::endl;
            }
        }
    }

    // check if webServers needs to be expanded
    if (requestQueue.size() > (5 * webServers.size())) {
        WebServer ws;
        if (availableWebServerIds.empty()) {
            ws = WebServer(webServers.size());
        }
        else {
            ws = WebServer(availableWebServerIds.front());
            availableWebServerIds.pop();
        }
        webServers.push_back(ws);
        // log that webServer was created
        servers_created++;
        std::cout << "Created WebServer with ID " << ws.id << std::endl;
    }
}

void LoadBalancer::pushNewRequest() {
    Request r;
    r.id = requestQueue.size();
    requestQueue.push(r);
}