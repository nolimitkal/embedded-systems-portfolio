#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H


#include <stdint.h>

typedef enum {
    STATE_GREEN,
    STATE_YELLOW,
    STATE_RED
} TrafficLightState;

typedef struct {
    TrafficLightState currentState;
    int timer; // in seconds
} TrafficLight;


// Function that takes point to a Traffic Light
void init_traffic_light(TrafficLight *light);

// Function that takes point to a Traffic Light 
void run_state_machine(TrafficLight* light);

// Function that runs a cycle of the state machine using function pointers
void run_state_machine_fp(TrafficLight *light);


#endif // STATE_MACHINE_H