#include "webserver.h"


WebServer::WebServer() {
    isBusy = false;
}

void WebServer::assignRequest(Request r) {
    request = r;
}

void WebServer::runOneCycle() {
    request.timeLeft--;
    if (request.timeLeft < 1) {
        isBusy = false;
    }
}