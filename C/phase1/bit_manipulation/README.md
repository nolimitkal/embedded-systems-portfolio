# Bit Manipulation Library in C

A register-level bit manipulation library implemented in pure C, simulating how
embedded systems firmware controls hardware peripherals by setting, clearing,
toggling, and reading individual bits in memory-mapped registers.

---

## Overview

In embedded systems every peripheral — GPIO pins, UART, timers, ADC, and
interrupts — is controlled through memory-mapped registers. These registers
are 32-bit values where each individual bit controls a specific hardware
feature.

For example on an STM32:
- Bit 5 of a GPIO output register turns pin 5 ON or OFF
- Bit 0 of a UART control register enables or disables the peripheral
- You cannot write a whole new value — you must set, clear, or toggle
  specific bits without disturbing the others

This project implements a bit manipulation library that simulates exactly
these register-level operations used in production embedded firmware.

---
## Skills Demonstrated

- Embedded C register manipulation
- Bitwise operations and bit masking
- Macro-based design for zero-cost abstractions
- Fixed-width integer types for hardware portability
- Pointer vs value parameter design decisions
- Modular C code organization (`.h`/`.c` separation)
- GCC compilation and debugging with `-Wall -Wextra`
- Version control with Git

## Technical Implementation

### Architecture
- **Simulated Register** — `uint32_t` variable representing a 32-bit hardware register
- **Bit Masks** — `(1U << n)` creates a mask targeting only bit n
- **Macro-based operations** — preprocessor macros for fast, reusable bit operations
- **Function wrappers** — clean function interface over the macros

### Register Layout

SIMULATED 32-BIT REGISTER
Bit: 31 30 29 28 ... 7 6 5 4 3 2 1 0
Val: 0 0 0 0 ... 0 0 1 0 1 0 0 0
▲ ▲
Bit 5 Bit 3 are SET

### Core Macros

| Macro | Operation | Example |
|-------|-----------|---------|
| `SET_BIT(reg, bit)` | Forces bit to 1 | `SET_BIT(reg, 5)` |
| `CLEAR_BIT(reg, bit)` | Forces bit to 0 | `CLEAR_BIT(reg, 5)` |
| `TOGGLE_BIT(reg, bit)` | Flips bit state | `TOGGLE_BIT(reg, 3)` |
| `CHECK_BIT(reg, bit)` | Reads bit state | `CHECK_BIT(reg, 3)` |

### Core Functions

| Function | Description |
|----------|-------------|
| `set_bit(reg, bit)` | Sets a specific bit in a register |
| `clear_bit(reg, bit)` | Clears a specific bit in a register |
| `toggle_bit(reg, bit)` | Toggles a specific bit in a register |
| `check_bit(reg, bit)` | Returns the state of a specific bit |
| `print_register(reg)` | Prints register in hex, binary, and decimal |

---

## C Concepts Demonstrated

| Concept | Application |
|---------|-------------|
| Bitwise OR `\|=` | Setting bits without affecting others |
| Bitwise AND `&=` | Clearing bits without affecting others |
| Bitwise XOR `^=` | Toggling bits without affecting others |
| Bitwise NOT `~` | Inverting a mask for bit clearing |
| Left shift `<<` | Creating bit masks at specific positions |
| `uint32_t` | Fixed-width type representing a 32-bit hardware register |
| `uint8_t` | Fixed-width type for bit position parameter |
| Macros `#define` | Reusable, zero-cost bit operation expressions |
| Pointer vs value | Modify functions take `*reg`, read functions take `reg` |
| `%08X` format | Printing register values in standard hex format |

---

## Learning Note

During development an important distinction was clarified — `check_bit`
takes the register **value** directly (`uint32_t reg`) rather than a pointer
(`uint32_t *reg`) because it only reads the register without modifying it.
The other three functions take a pointer because they modify the register
in place. This pattern — passing pointers only when modification is needed
— is a fundamental embedded C design principle.

---

## Edge Cases & Observations

- Setting then clearing the same bit returns register to original state
- Toggling a bit twice returns it to its original state
- `CHECK_BIT` returns `0` or `1` only — clean boolean result
- All operations preserve unaffected bits

---

## Project Structure
```
bit_manipulation/
├── bit_manipulation.h    # Macros, typedefs, function declarations
├── bit_manipulation.c    # Core function implementations
├── main.c                # Test suite simulating register operations
└── README.md             # Project documentation
```

---

## Build & Run

**Requirements:** GCC

```bash
gcc -Wall -Wextra -g main.c bit_manipulation.c -o bit_manipulation
./bit_manipulation
```

---

## Sample Output
=== Initial State ===
Register value: 0x00000000
Binary representation: 00000000000000000000000000000000
Decimal value: 0

=== After SET bit 5 ===
Register value: 0x00000020
Binary representation: 00000000000000000000000000100000
Decimal value: 32

=== After CLEAR bit 5 ===
Register value: 0x00000000
Binary representation: 00000000000000000000000000000000
Decimal value: 0

=== After TOGGLE bit 3 ===
Register value: 0x00000008
Binary representation: 00000000000000000000000000001000
Decimal value: 8

=== After TOGGLE bit 3 again ===
Register value: 0x00000000
Binary representation: 00000000000000000000000000000000
Decimal value: 0

=== CHECK bit 3 ===
Bit 3 is: 0

---

