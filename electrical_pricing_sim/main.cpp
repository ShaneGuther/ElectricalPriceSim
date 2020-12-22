#include <iostream>
#include "Simulation.h"
int main() {
    std::cout << "Testing " << std::endl;
    Simulation *sim = new Simulation();
    sim->printResult();
    delete sim;

    return 0;
}
