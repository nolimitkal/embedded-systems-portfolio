#include "bit_manipulation.h"
#include <stdio.h>

//Implemetation of bit manipulation functions
void set_bit(uint32_t *reg, uint8_t bit) {
    SET_BIT(*reg, bit);
}


void clear_bit(uint32_t *reg, uint8_t bit) {
    CLEAR_BIT(*reg, bit);
}

void toggle_bit(uint32_t *reg, uint8_t bit) {
    TOGGLE_BIT(*reg, bit);
}

uint8_t check_bit(uint32_t reg, uint8_t bit) {
    return CHECK_BIT(reg, bit);
}


void print_register(uint32_t reg) {

    // print hex value using %08X
    printf("Register value: 0x%08X\n", reg);

    // print binary by looping from bit 31 down to bit 0
    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) {
        printf("%u", CHECK_BIT(reg, i)); // CHECK_BIT macro to read each bit
    }
    printf("\n");
    
    //print decimal using %u
    printf("Decimal value: %u\n", reg);
}