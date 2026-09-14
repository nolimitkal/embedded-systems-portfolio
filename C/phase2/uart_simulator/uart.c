#include "uart.h"
#include <stdio.h>

uint8_t calculate_parity(uint8_t data) {
    uint8_t count = 0;
    for (int i = 0; i < 8; i++) {
        if ((data >> i) & 1) {
            count++;
        }
    }
    return (count % 2 == 0) ? 0 : 1; // Return 0 for even parity, 1 for odd parity
}

UARTFrame uart_encode(uint8_t data) {
    UARTFrame frame;
    frame.start_bit = 0;
    frame.data_bits = data;
    frame.parity_bit = calculate_parity(data);
    frame.stop_bit = 1;
    return frame;
}


uint8_t uart_decode(UARTFrame frame) {
    return frame.data_bits;
}


void uart_print_frame(UARTFrame frame) {
    printf("Start Bit: %d\n", frame.start_bit);
    printf("Data Bits: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (frame.data_bits >> i) & 1);
    }
    printf("\n");
    printf("Parity Bit: %d\n", frame.parity_bit);
    printf("Stop Bit: %d\n", frame.stop_bit);
}