
#include "can_bus.h"
#include <string.h>
#include <stdio.h>


int main() {
    uint8_t dataA[2] = {0x11, 0x22};
    uint8_t dataB[3] = {0x33, 0x44, 0x55};
    uint8_t dataC[1] = {0x01};

    CANFrame frameA = can_frame_create(0x100, 2, dataA);
    CANFrame frameB = can_frame_create(0x200, 3, dataB);
    CANFrame frameC = can_frame_create(0x050, 1, dataC);

    printf("Node A Frame:\n");
    can_frame_print(frameA);

    printf("Node B Frame:\n");
    can_frame_print(frameB);

    printf("Node C Frame:\n");
    can_frame_print(frameC);




    CANFrame frames[3] = {frameA, frameB, frameC};


    CANFrame winner = can_arbitrate(frames, 3);

    printf("Winning Frame:\n");
    can_frame_print(winner);
    return 0;
}
    