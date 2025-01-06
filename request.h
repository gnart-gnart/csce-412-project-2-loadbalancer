#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @struct Request
 * @brief Represents a web request with IP addresses, processing time, and job type.
 */
struct Request {
    Request();
    Request(int id);
    std::string IP_IN; ///< The incoming IP address.
    std::string IP_OUT; ///< The outgoing IP address.
    int timeLeft; ///< The remaining processing time.
    int id; ///< The unique ID of the request.
    char jobType; ///< The type of job ('S' for streaming, 'P' for processing).
};

#endif