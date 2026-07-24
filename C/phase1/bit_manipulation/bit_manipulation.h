#ifndef BIT_MANIPULATION_H // header guard to prevent multiple inclusions
#define BIT_MANIPULATION_H

#include <stdint.h>

// Macros for bit manipulation operations(reusable expressions)
#define SET_BIT(reg, bit) ((reg) |= (1U << (bit)))
#define CLEAR_BIT(reg, bit) ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1U << (bit)))
#define CHECK_BIT(reg, bit) (((reg) >> (bit)) & 1U)


void set_bit(uint32_t *reg, uint8_t bit);
void clear_bit(uint32_t *reg, uint8_t bit);
void toggle_bit(uint32_t *reg, uint8_t bit);
uint8_t check_bit(uint32_t reg, uint8_t bit);

void print_register(uint32_t reg);


#endif // BIT_MANIPULATION_H