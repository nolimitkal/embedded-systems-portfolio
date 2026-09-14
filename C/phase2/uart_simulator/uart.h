#ifndef UART_H
#define UART_H

#include <stdint.h>

typedef struct {
    uint8_t start_bit;
    uint8_t data_bits;
    uint8_t parity_bit;
    uint8_t stop_bit;
} UARTFrame;

uint8_t calculate_parity(uint8_t data);
UARTFrame uart_encode(uint8_t data);
uint8_t uart_decode(UARTFrame frame);


void uart_print_frame(UARTFrame frame);
#endif // UART_H