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


void run_state_machine(TrafficLight* light);


#endif // STATE_MACHINE_H