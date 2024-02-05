#ifndef ESP_ECU_H
#define ESP_ECU_H

// ZIGBEE
#define CC2530_MAX_SERIAL_BUFFER_SIZE 512

// APP
#define MAX_NUMBER_OF_INVERTERS 9

// HARDWARE

void ledblink(int i, int wacht);
void empty_serial();

// ZIGBEE PINS
#define ZB_RESET          14 // D5
#define ZB_TX             15 // D8

#endif