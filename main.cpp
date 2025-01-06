#include <iostream>
#include "loadbalancer.h"

LoadBalancer loadBalancer;

void run_load_balancer(int num_clock_cycles, int num_web_servers) {
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
    int num_clock_cycles = 0;
    int num_web_servers = 0;

    std::cout << "Enter the number of clock cycles:" << std::endl;
    std::cin >> num_clock_cycles;
    std::cout << "Enter the number of webservers:" << std::endl;
    std::cin >> num_web_servers;

    std::cout << "Running " << num_clock_cycles << " cycles with " 
        << num_web_servers << " servers..." << std::endl;
    run_load_balancer(num_clock_cycles, num_web_servers);
    std::cout << "\nDone!" << std::endl;

    return 0;
}