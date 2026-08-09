#include "state_machine.h"
#include <stdio.h>

// Function that takes point to a Traffic Light
// Sets current_state to STATE_RED
// Sets timer to 5
void init_traffic_light(TrafficLight* light) {
    light->currentState = STATE_RED;
    light->timer = 5;
}

// Function that runs a cycle of the state machine using a switch statement
// Print current state and its action
// Transition to next state 
void run_state_machine(TrafficLight* light) {
    switch (light->currentState) {
        case STATE_GREEN:
            printf("Current state: Green\n");
            light->currentState = STATE_YELLOW;
            break;
        case STATE_YELLOW:
            printf("Current state: Yellow\n");
            light->currentState = STATE_RED;
            break;
        case STATE_RED:
            printf("Current state: Red\n");
            light->currentState = STATE_GREEN;
            break;
    }

}