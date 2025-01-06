#include <iostream>
#include "loadbalancer.h"

LoadBalancer loadBalancer;

void run_load_balancer(int num_clock_cycles, int num_web_servers) {
    loadBalancer.createWebservers(num_web_servers);
    for (int i = 0; i < num_clock_cycles; i++) {
        loadBalancer.runOneCycle();
    }
}

int main(int argc, char* argv[]) {
    int num_clock_cycles = 0;
    int num_web_servers = 0;

    std::cout << "Enter the number of clock cycles:" << std::endl;
    std::cin >> num_clock_cycles;
    std::cout << "Enter the number of webservers:" << std::endl;
    std::cin >> num_web_servers;

    std::cout << "Running " << num_clock_cycles << " cycles..." << std::endl;
    run_load_balancer(num_clock_cycles, num_web_servers);
    std::cout << "Done!" << std::endl;

    return 0;
}