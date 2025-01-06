#include "webserver.h"

/**
 * @brief Constructs a WebServer object with default values.
 */
WebServer::WebServer() {
    isBusy = false;
    this->id = -1;
}

/**
 * @brief Constructs a WebServer object with a specified ID.
 * @param id The unique ID of the web server.
 */
WebServer::WebServer(int id) {
    isBusy = false;
    this->id = id;
}

/**
 * @brief Assigns a request to the web server.
 * @param r The request to assign.
 */
void WebServer::assignRequest(Request r) {
    request = r;
    isBusy = true;
}

/**
 * @brief Simulates one cycle of request processing.
 */
void WebServer::runOneCycle() {
    if (isBusy) {
        request.timeLeft--;
        if (request.timeLeft < 1) {
            isBusy = false;
        }
    }
}