# UART Protocol Simulator in C

A UART (Universal Asynchronous Receiver-Transmitter) protocol simulator
implemented in pure C, demonstrating frame encoding, decoding, and parity
based error detection used in serial communication.

---

## Overview

UART is one of the most widely used serial protocols in embedded systems,
commonly used for debugging consoles, GPS modules, Bluetooth modules, and
point to point communication between microcontrollers. This project
simulates the full UART frame lifecycle in software, including start bit,
data bits, parity bit, and stop bit handling, along with error detection
using parity checking.

---

## Skills Demonstrated

- UART protocol frame structure implementation in C
- Bitwise operations for frame encoding and decoding
- Parity based error detection logic
- Struct based data representation for hardware protocols
- Fixed width integer types for hardware accurate data representation
- Modular C code organization
- GCC compilation and debugging with -Wall -Wextra
- Version control with Git

---

## Technical Implementation

### UART Frame Structure

```

┌───────┬────────────────┬────────┬──────┐
│ Start │ Data (8 bits) │ Parity │ Stop │
│ bit │ │ bit │ bit │
└───────┴────────────────┴────────┴──────┘
1 bit 8 bits 1 bit 1 bit

```


### Encoding Process

```

Byte to send: 0x41 ('A')
│
▼
Set start bit to 0
│
▼
Store 8 data bits
│
▼
Calculate parity bit (even parity)
│
▼
Set stop bit to 1
│
▼
Complete UART frame ready to transmit

```


### Parity Error Detection

Even parity is used, meaning the total number of 1 bits in the data plus
the parity bit must always be even. If a single bit is corrupted during
transmission, recalculating the parity on the receiving end will not match
the transmitted parity bit, signaling a transmission error.

### Core Functions

```

| Function | Description |
|----------|-------------|
| `calculate_parity(data)` | Calculates the even parity bit for a given byte |
| `uart_encode(data)` | Constructs a complete UART frame from a raw byte |
| `uart_decode(frame)` | Extracts the original data byte from a UART frame |
| `uart_print_frame(frame)` | Prints all frame fields including binary data representation |

```

---

## Project Structure

```

uart_simulator/
├── uart.h # UARTFrame struct and function declarations
├── uart.c # Encoding, decoding, parity, and print logic
├── main.c # Tests encode/decode round trip and parity error detection
└── README.md # Project documentation

```


---

## Build & Run

**Requirements:** GCC

```bash
gcc -Wall -Wextra -g main.c uart.c -o uart
./uart
```

---

## Sample Output

Start Bit: 0
Data Bits: 01000001
Parity Bit: 0
Stop Bit: 1
Original: 0x41, Decoded: 0x41
Parity Error Detected!


The first section confirms a successful encode and decode round trip. The
final line confirms that flipping a single bit in the data causes the
parity check to correctly detect the transmission error.