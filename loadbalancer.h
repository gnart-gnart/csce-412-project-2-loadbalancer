#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include <queue>
#include <vector>
#include <string.h>
#include "request.h"
#include "webserver.h"

/**
 * @class LoadBalancer
 * @brief Manages a pool of web servers and a queue of requests.
 *
 * The LoadBalancer distributes incoming requests to available web servers
 * and dynamically adjusts the number of servers based on the load.
 */
class LoadBalancer {
private:
    std::vector<WebServer> webServers; ///< List of active web servers.
    std::queue<Request> requestQueue; ///< Queue of pending requests.
    std::queue<int> availableWebServerIds; ///< Queue of available server IDs for reuse.
    bool verboseLogging; ///< Flag to enable verbose logging.

public:
    LoadBalancer();
    void runOneCycle(std::string time);
    void createWebservers(int num_web_servers);
    void pushNewRequest();

    int getServersLeft();
    int getRequestsLeft();

    void setVerboseLogging(bool verbose);

    int servers_created = 0; ///< Number of servers created during runtime.
    int servers_deleted = 0; ///< Number of servers deleted during runtime.
    int requests_finished = 0; ///< Number of requests completed.
};

#endif