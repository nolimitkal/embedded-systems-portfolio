# Custom Memory Allocator in C

A custom dynamic memory allocator implemented in pure C, simulating how embedded 
systems firmware manages memory without relying on the standard library's `malloc` 
and `free`. This project demonstrates low-level memory management concepts critical 
to embedded software engineering.

---

## Overview

In embedded systems, standard `malloc` is often unavailable or unsafe due to:
- Non-deterministic allocation timing
- Heap fragmentation over long runtimes
- Limited or no standard library support on bare-metal MCUs

This project implements a custom memory allocator using a fixed memory pool — the 
same approach used in production embedded firmware for automotive ECUs, medical 
devices, and aerospace systems.

---

## Technical Implementation

### Architecture
- **Fixed Memory Pool** — 1024-byte static array acting as a custom heap
- **Block Header Struct** — metadata tracking size and availability of each block
- **First-Fit Algorithm** — walks the pool to find the first suitable free block
- **Pointer Arithmetic** — manual navigation between memory blocks

### Memory Layout
MEMORY POOL (1024 bytes)
┌──────────────────┬──────────────────────┬─────────────────┐
│ BlockHeader      │ Data                 │ BlockHeader ... │
│ size | is_free   │ (usable memory)      │ size | is_free  │
└──────────────────┴──────────────────────┴─────────────────┘

### Core Functions

| Function | Description |
|----------|-------------|
| `allocator_init()` | Initializes the memory pool with a single free block |
| `my_malloc(size)` | Allocates a block of memory from the pool |
| `my_free(ptr)` | Returns a block to the pool |
| `allocator_print_pool()` | Debug utility to print pool state |

---

## C Concepts Demonstrated

| Concept | Application |
|---------|-------------|
| Structs | `BlockHeader` tracks block metadata |
| Pointer arithmetic | Navigating between memory blocks |
| Pointer casting | Interpreting raw bytes as typed structures |
| `static` keyword | Encapsulating the memory pool within the module |
| `size_t` / `uint8_t` | Portable embedded-friendly types |
| Header guards | Preventing multiple inclusion in `allocator.h` |
| `void *` | Generic pointer for type-agnostic allocation |
| NULL handling | Defensive programming against invalid pointers |

---

## Edge Cases Handled

- Allocation request larger than pool size → returns `NULL`
- Pool fully exhausted → returns `NULL`
- `my_free(NULL)` → handled safely with no crash
- Zero size allocation request → returns `NULL`

---

## Project Structure
memory_allocator/
├── allocator.h    # Block header struct, constants, function declarations
├── allocator.c    # Core allocator implementation
├── main.c         # Test suite with edge case validation
└── README.md      # Project documentation
---

## Build & Run

**Requirements:** GCC

```bash
gcc -Wall -Wextra -g main.c allocator.c -o allocator
./allocator
```

---

## Sample Output

Test 1 PASSED: Allocation successful
Test 1: Memory freed
Test 2 PASSED: Oversized allocation correctly returned NULL
Test 3 PASSED: Pool full, allocation correctly returned NULL
Test 4 PASSED: my_free(NULL) handled safely
=== Initial Pool State ===
Block 0: Size = 1008, Is Free = 1
Total blocks in pool: 1
=== After malloc(32) ===
Block 0: Size = 1008, Is Free = 0
Total blocks in pool: 1
=== After free ===
Block 0: Size = 1008, Is Free = 1
Total blocks in pool: 1

---

## Skills Demonstrated

- Embedded C programming
- Low-level memory management
- Pointer manipulation and arithmetic
- Defensive programming and edge case handling
- Modular C code organization (`.h`/`.c` separation)
- GCC compilation and debugging with `-Wall -Wextra`
- Version control with Git