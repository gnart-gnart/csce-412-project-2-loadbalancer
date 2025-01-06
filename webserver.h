#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

/**
 * @class WebServer
 * @brief Represents a web server that processes requests.
 */
class WebServer {
public:
    WebServer();
    WebServer(int id);
    Request request; ///< The current request being processed.
    bool isBusy; ///< Indicates whether the server is busy processing a request.
    void assignRequest(Request r);
    void runOneCycle();
    int id; ///< The unique ID of the web server.
};

#endif