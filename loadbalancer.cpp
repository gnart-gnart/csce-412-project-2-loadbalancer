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
    availableWebServerIds.push(webServers.size() + 1);
}

void LoadBalancer::runOneCycle(std::string time) {

    for (int i = 0; i < webServers.size(); i++) {

        WebServer& current = webServers.at(i);

        if (!(current.isBusy)) {
            // try to assign a request
            if (requestQueue.empty()) {
                // try to delete web server
                if (webServers.size() > 3) {
                    // log that webServer is deleted
                    std::cout << "WebServer " << current.id << " deleted" << std::endl;
                    servers_deleted++;
                    webServers.erase(webServers.begin() + i);
                    availableWebServerIds.push(i + 1);
                    i--;
                }
                continue;
            }
            // assign request
            current.assignRequest(requestQueue.front());
            requestQueue.pop();
            std::cout << time << ": WebServer " << current.id << " assigned Request " 
                << current.request.id << std::endl;
        }

        current.runOneCycle();

        if (!current.isBusy) {
            std::cout << time << ": WebServer " << current.id << 
                " finished Request " << current.request.id << std::endl;
            requests_finished++;
        }

        // check if webServers needs to be expanded
        if (requestQueue.size() > (5 * webServers.size())) {
            WebServer ws;
            if (availableWebServerIds.empty()) {
                ws = WebServer(webServers.size() + 1);
            }
            else {
                ws = WebServer(availableWebServerIds.front());
                availableWebServerIds.pop();
            }
            webServers.push_back(ws);
            servers_created++;
            std::cout << time << ": Created WebServer with ID " << ws.id << std::endl;
        }
    }
}

int LoadBalancer::getServersLeft() {
    return webServers.size();
}

int LoadBalancer::getRequestsLeft() {
    return requestQueue.size();
}

void LoadBalancer::pushNewRequest() {
    Request r(requestQueue.size());
    requestQueue.push(r);
}