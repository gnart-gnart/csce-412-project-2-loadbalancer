## Description and How to Run
This is a project for a class. It simulates a load balancer (not a full or complete implementation).
To run the simulation, compile the program and execute it with the desired number of clock cycles (-c) and web servers (-w). Use the -v flag for verbose logging.
Example:
```make run ARGS="-c 500 -w 5 -v"```
(runs the program with 500 clock cycles and 5 initial web servers. Uses verbose logging)
```make run```
(runs it with the default values: 10,000 cycles, 20 web servers, no verbose logging)
