#include <iostream>
#include "loadbalancer.h"
#include <cstring>

LoadBalancer loadBalancer;

void run_load_balancer(int num_clock_cycles, int num_web_servers, bool verbose) {
    loadBalancer.setVerboseLogging(verbose);
    loadBalancer.createWebservers(num_web_servers);

    for (int i = 0; i < num_clock_cycles; i++) {
        loadBalancer.runOneCycle("T" + std::to_string(i));
        if ((rand() % 5) == 0) {
            loadBalancer.pushNewRequest();
        }
    }

    std::cout << "Finished " << loadBalancer.requests_finished << " requests."
        << std::endl << "Created " << loadBalancer.servers_created << " servers."
        << std::endl << "Deleted " << loadBalancer.servers_deleted << " servers."
        << std::endl << "There are " << loadBalancer.getServersLeft() << " servers left."
        << std::endl << "There are " << loadBalancer.getRequestsLeft() << " requests left.\n";
}

int main(int argc, char* argv[]) {
    int num_clock_cycles = 10000;
    int num_web_servers = 20;
    bool verbose = true;

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
    std::cout << "\nDone!" << std::endl;

    return 0;
}