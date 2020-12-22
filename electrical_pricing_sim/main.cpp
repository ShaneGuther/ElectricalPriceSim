#include <iostream>
#include "Simulation.h"
int main() {
    Simulation *sim = new Simulation();
    sim->printResult();
    delete sim;

    return 0;
}
