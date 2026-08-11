// Create two TrafficLight instances
// Initializes both
// Runs using run_state_machine for 6 cycles
// Runs the other using run_state_machine_fp for 6 cycles
//Prints headers to separate the two runs
#include <stdio.h>
#include "state_machine.h"
#include <stdint.h>

int main() {
    TrafficLight light1;
    TrafficLight light2;

    init_traffic_light(&light1);
    init_traffic_light(&light2);

    printf("Running state machine using switch statement:\n");
    for (int i = 0; i < 6; i++) {
        run_state_machine(&light1);
    }

    printf("\nRunning state machine using function pointers:\n");
    for (int i = 0; i < 6; i++) {
        run_state_machine_fp(&light2);
    }

    return 0;
}