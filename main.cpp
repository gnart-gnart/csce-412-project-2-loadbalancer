#include <iostream>
#include "loadbalancer.h"
#include <cstring>

LoadBalancer loadBalancer;

/**
 * @brief Runs the load balancer simulation.
 * @param num_clock_cycles The number of clock cycles to simulate.
 * @param num_web_servers The number of web servers to create.
 * @param verbose If true, enables verbose logging.
 */
void run_load_balancer(int num_clock_cycles, int num_web_servers, bool verbose) {
    loadBalancer.setVerboseLogging(verbose);
    loadBalancer.createWebservers(num_web_servers);

    for (int i = 0; i < num_clock_cycles; i++) {
        loadBalancer.runOneCycle("T" + std::to_string(i));
        if ((rand() % 5) == 0) {
            loadBalancer.pushNewRequest();
        }
    }

    std::cout << std::endl
        << "Started with " << std::to_string(num_web_servers * 5) << " requests in queue."
        << std::endl << "Ended with " << loadBalancer.getRequestsLeft() << " request in queue."
        << std::endl << "Range for task times: 10-100"
        << std::endl << "Added " << loadBalancer.servers_created << " servers."
        << std::endl << "Deleted " << loadBalancer.servers_deleted << " servers."
        << std::endl
        << std::endl << "There are " << loadBalancer.getServersLeft() << " servers left."
        << std::endl << "Finished " << loadBalancer.requests_finished << " requests."
        << std::endl;
}

/**
 * @brief The main function to run the load balancer simulation.
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return 0 on success, 1 on failure.
 */
int main(int argc, char* argv[]) {
    int num_clock_cycles = 10000;
    int num_web_servers = 20;
    bool verbose = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            num_clock_cycles = std::stoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-w") == 0 && i + 1 < argc) {
            num_web_servers = std::stoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = true;
        }
    }

    if (num_clock_cycles <= 0 || num_web_servers <= 0) {
        std::cerr << "Invalid input(s)." << std::endl;
        return 1;
    }

    std::cout << "Running " << num_clock_cycles << " cycles with " 
        << num_web_servers << " servers..." << std::endl;
    run_load_balancer(num_clock_cycles, num_web_servers, verbose);
    std::cout << "Done!" << std::endl;

    return 0;
}