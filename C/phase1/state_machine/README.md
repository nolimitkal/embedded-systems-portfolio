# State Machine Implementation in C

A finite state machine implementation in pure C simulating a traffic light
controller, demonstrating two industry standard implementation patterns used
in embedded firmware development.

---

## Overview

State machines are used extensively in embedded systems to manage complex
behavior in a structured and predictable way. This project implements a
traffic light controller using two different patterns commonly found in
production firmware, from simple bare metal applications to communication
protocol handling.

---

## Skills Demonstrated

- Finite state machine design and implementation in C
- Enum based state representation
- Struct based state machine data organization
- Switch statement based control flow
- Function pointer arrays for scalable state dispatch
- Modular C code organization
- GCC compilation and debugging with -Wall -Wextra
- Version control with Git

---

## Technical Implementation

### State Diagram
```
        ┌─────────────────────────────────┐
        │                                 │
        ▼                                 │
   [RED STATE]                            │
   Action: Stop                           │
        │                                 │
        ▼                                 │
  [GREEN STATE]                           │
  Action: Go                              │
        │                                 │
        ▼                                 │
  [YELLOW STATE]                          │
  Action: Caution                         │
        │                                 │
        └─────────────────────────────────┘
```
### Two Implementation Patterns

**Switch Statement Pattern**
A straightforward approach using a switch statement to handle state logic
and transitions. Simple and readable for small state machines.

**Function Pointer Pattern**
A scalable approach using an array of function pointers indexed by state.
Each state has a dedicated handler function, avoiding long switch statements
as the number of states grows. This pattern is commonly used in larger
production firmware.

### Core Functions

| Function | Description |
|----------|-------------|
| `init_traffic_light(light)` | Initializes the state machine to the starting state |
| `run_state_machine(light)` | Runs one cycle using the switch statement pattern |
| `run_state_machine_fp(light)` | Runs one cycle using the function pointer pattern |

---

## Project Structure

```
state_machine/
├── state_machine.h # State enum, struct, function declarations
├── state_machine.c # Both implementation patterns
├── main.c # Test suite running both patterns
└── README.md # Project documentation

```
---

## Build & Run

**Requirements:** GCC

```bash
gcc -Wall -Wextra -g main.c state_machine.c -o state_machine
./state_machine
```

---

## Sample Output
Running state machine using switch statement:
Current state: Red
Current state: Green
Current state: Yellow
Current state: Red
Current state: Green
Current state: Yellow

Running state machine using function pointers:
Current state: Red
Current state: Green
Current state: Yellow
Current state: Red
Current state: Green
Current state: Yellow