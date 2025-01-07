#include "loadbalancer.h"
#include <iostream>

/**
 * @brief Constructs a LoadBalancer object.
 */
LoadBalancer::LoadBalancer() : verboseLogging(false) {}

/**
 * @brief Sets the verbose logging mode.
 * @param verbose If true, enables verbose logging.
 */
void LoadBalancer::setVerboseLogging(bool verbose) {
    verboseLogging = verbose;
}

/**
 * @brief Creates a specified number of web servers and initializes the request queue.
 * @param num_web_servers The number of web servers to create.
 */
void LoadBalancer::createWebservers(int num_web_servers) {
    for (int i = 0; i < num_web_servers; i++) {
        webServers.push_back(WebServer(i + 1));
        for (int j = 0; j < 5; j++) {
            requestQueue.push(Request((i * 5) + j + 1));
        }
    }
    availableWebServerIds.push(webServers.size() + 1);
}

/**
 * @brief Simulates one cycle of the load balancer.
 * @param time The current time step as a string.
 */
void LoadBalancer::runOneCycle(std::string time) {
    for (int i = 0; i < webServers.size(); i++) {
        WebServer& current = webServers.at(i);

        if (!(current.isBusy)) {
            if (requestQueue.empty()) {
                if (webServers.size() > 3) {
                    if (verboseLogging) {
                        std::cout << "WebServer " << current.id << " deleted" << std::endl;
                    }
                    servers_deleted++;
                    webServers.erase(webServers.begin() + i);
                    availableWebServerIds.push(i + 1);
                    i--;
                }
                continue;
            }
            current.assignRequest(requestQueue.front());
            requestQueue.pop();
            if (verboseLogging) {
                std::cout << time << ": WebServer " << current.id << " assigned Request " 
                          << current.request.id << " (IP_IN: " << current.request.IP_IN 
                          << ", IP_OUT: " << current.request.IP_OUT << ")" << std::endl;
            }
        }

        current.runOneCycle();

        if (!current.isBusy) {
            if (verboseLogging) {
                std::cout << time << ": WebServer " << current.id 
                          << " finished Request " << current.request.id 
                          << " (IP_IN: " << current.request.IP_IN 
                          << ", IP_OUT: " << current.request.IP_OUT << ")" << std::endl;
            } else {
                std::cout << time << ": WebServer " << current.id 
                          << " finished Request " << current.request.id << std::endl;
            }
            requests_finished++;
        }

        if (requestQueue.size() > (4 * webServers.size())) {
            WebServer ws;
            if (availableWebServerIds.empty()) {
                ws = WebServer(webServers.size() + 1);
            } else {
                ws = WebServer(availableWebServerIds.front());
                availableWebServerIds.pop();
            }
            webServers.push_back(ws);
            servers_created++;
            if (verboseLogging) {
                std::cout << time << ": Created WebServer with ID " << ws.id << std::endl;
            }
        }
    }
}

/**
 * @brief Returns the number of active web servers.
 * @return The number of active web servers.
 */
int LoadBalancer::getServersLeft() {
    return webServers.size();
}

/**
 * @brief Returns the number of pending requests in the queue.
 * @return The number of pending requests.
 */
int LoadBalancer::getRequestsLeft() {
    return requestQueue.size();
}

/**
 * @brief Adds a new request to the queue.
 */
void LoadBalancer::pushNewRequest() {
    Request r(requestQueue.size());
    requestQueue.push(r);
}