# CAN Bus Simulator in C

A CAN (Controller Area Network) protocol simulator implemented in pure C,
demonstrating frame structure, multi-node message creation, and bus
arbitration logic used in automotive embedded systems.

---

## Overview

CAN is the primary communication protocol used in automotive ECUs. Every
modern vehicle has dozens of ECUs, engine control, transmission, ABS, and
infotainment, communicating over a shared CAN bus. This project simulates
core CAN bus behavior in software, focusing on frame structure and
arbitration, the mechanism that resolves conflicts when multiple nodes
attempt to transmit simultaneously.

---

## Skills Demonstrated

- CAN protocol frame structure implementation in C
- Struct based data representation for hardware protocols
- Multi-node communication simulation
- Bus arbitration logic based on message priority
- Fixed width integer types for hardware accurate data representation
- Modular C code organization
- GCC compilation and debugging with -Wall -Wextra
- Version control with Git

---

## Technical Implementation

### CAN Frame Structure

```
┌──────┬──────┬──────────────────┐
│  ID  │ DLC  │   Data[8]        │
│uint32│ uint8│   uint8_t array  │
└──────┴──────┴──────────────────┘
```

### Bus Arbitration

SIMULATED CAN BUS

Node A (ID: 0x100) ──┐
Node B (ID: 0x200) ──┼──► [ARBITRATION] ──► Winning Frame
Node C (ID: 0x050) ──┘ │
Lowest ID wins


CAN is a broadcast protocol where message priority is determined by the
numeric value of the message ID. When multiple nodes transmit at the same
time, the frame with the lowest ID wins arbitration and gains access to
the bus, while other nodes back off and retry.

### Core Functions

| Function | Description |
|----------|-------------|
| `can_frame_create(id, dlc, data)` | Constructs a CAN frame with the given ID, data length, and payload |
| `can_frame_print(frame)` | Prints a frame's ID, DLC, and data bytes in hex format |
| `can_arbitrate(frames, count)` | Simulates bus arbitration, returning the frame with the lowest ID |

---

## Project Structure

can_bus_simulator/
├── can_bus.h # CANFrame struct and function declarations
├── can_bus.c # Frame creation, printing, and arbitration logic
├── main.c # Simulates three nodes and tests arbitration
└── README.md # Project documentation


---

## Build & Run

**Requirements:** GCC

```bash
gcc -Wall -Wextra -g main.c can_bus.c -o can_bus
./can_bus
```

---

## Sample Output

Node A Frame:
CAN Frame ID: 0x100
DLC: 2
Data: 0x11 0x22

Node B Frame:
CAN Frame ID: 0x200
DLC: 3
Data: 0x33 0x44 0x55

Node C Frame:
CAN Frame ID: 0x50
DLC: 1
Data: 0x01

Winning Frame:
CAN Frame ID: 0x50
DLC: 1
Data: 0x01


Node C wins arbitration since 0x50 is the lowest ID among the three
transmitting nodes, correctly demonstrating CAN bus priority resolution.