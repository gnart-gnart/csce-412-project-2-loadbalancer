#include "webserver.h"

WebServer::WebServer() {
    isBusy = false;
    this->id = -1;
}

WebServer::WebServer(int id) {
    isBusy = false;
    this->id = id;
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