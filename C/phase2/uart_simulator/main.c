
#include "uart.h"
#include <stdio.h>


int main() {
    uint8_t original = 0x41; // Example: 'A'
    UARTFrame frame = uart_encode(original);
    uart_print_frame(frame);
    uint8_t decoded = uart_decode(frame);
    printf("Original: 0x%02X, Decoded: 0x%02X\n", original, decoded);


UARTFrame corrupted_frame = frame; // Copy the original frame
corrupted_frame.data_bits ^= 0x01; // Flip the least significant bit to simulate a transmission error
uint8_t expected_parity = calculate_parity(corrupted_frame.data_bits); // Recalculate the expected parity for the corrupted data

if (expected_parity != corrupted_frame.parity_bit) {
    printf("Parity Error Detected!\n");
} else {
    printf("No Parity Error\n");
}

return 0;
}






