// TODO: Add header guard (CAN_BUS_H)
#ifndef CAN_BUS_H
#define CAN_BUS_H

// TODO: Include stdint.h for fixed width types
#include <stdint.h>

// TODO: Define a struct called CANFrame with three fields:
        typedef struct{
            uint32_t id;           // message identifier
            uint8_t dlc;           // data length code, 0-8
            uint8_t data[8];       // data payload, max 8 bytes
        } CANFrame;


CANFrame can_frame_create(uint32_t id, uint8_t dlc, const uint8_t* data);




void can_frame_print(CANFrame frame);




CANFrame can_arbitrate(CANFrame* frames, uint8_t count);
#endif // CAN_BUS_H