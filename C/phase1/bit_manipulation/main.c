#include "bit_manipulation.h"
#include <stdio.h>

int main() {

    uint32_t reg = 0x00000000; // simulated hardware register, all bits cleared

    // print initial register state
    printf("=== Initial State ===\n");
    print_register(reg);

    // set bit 5 — simulates enabling a GPIO pin
    printf("\n=== After SET bit 5 ===\n");
    set_bit(&reg, 5);
    print_register(reg);

    // clear bit 5 — simulates disabling a GPIO pin
    printf("\n=== After CLEAR bit 5 ===\n");
    clear_bit(&reg, 5);
    print_register(reg);

    // toggle bit 3 — simulates flipping a pin state
    printf("\n=== After TOGGLE bit 3 ===\n");
    toggle_bit(&reg, 3);
    print_register(reg);

    // toggle bit 3 again — should return to original state
    printf("\n=== After TOGGLE bit 3 again ===\n");
    toggle_bit(&reg, 3);
    print_register(reg);

    // check bit 3 — reads current state of bit 3
    printf("\n=== CHECK bit 3 ===\n");
    uint8_t result = check_bit(reg, 3); // passes value not pointer — read only
    printf("Bit 3 is: %u\n", result);

    return 0;
}