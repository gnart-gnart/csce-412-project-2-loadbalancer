#include "loadbalancer.h"


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
                    webServers.erase(webServers.begin() + i);
                    availableWebServerIds.push(i + 1);
                    i--;
                    // TODO: log that webServer finished task
                }
            }
            else {
                current.assignRequest(requestQueue.front());
                requestQueue.pop();
                // TODO: log that webServer assigned request and finished task
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
        // TODO: log that webServer was created
    }
}

void LoadBalancer::pushNewRequest() {
    Request r;
    r.id = requestQueue.size();
    requestQueue.push(r);
}