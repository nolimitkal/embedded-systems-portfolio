#include "can_bus.h"
#include <string.h>
#include <stdio.h>



CANFrame can_frame_create(uint32_t id, uint8_t dlc, const uint8_t* data) {
    CANFrame frame;
    frame.id = id;
    frame.dlc = dlc;
    memcpy(frame.data, data, dlc);
    return frame;
}

void can_frame_print(CANFrame frame) {
    printf("CAN Frame ID: 0x%X\n", frame.id);
    printf("DLC: %d\n", frame.dlc);
    printf("Data: ");
    for (uint8_t i = 0; i < frame.dlc; i++) {
        printf("0x%02X ", frame.data[i]);
    }
    printf("\n");
}


CANFrame can_arbitrate(CANFrame* frames, uint8_t count) {
    CANFrame winner = frames[0];
    for (uint8_t i = 1; i < count; i++) {
        if (frames[i].id < winner.id) {
            winner = frames[i];
        }
    }
    return winner;
}
