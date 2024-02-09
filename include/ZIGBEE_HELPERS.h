#ifndef ZIGBEE_HELPERS_H
#define ZIGBEE_HELPERS_H

#include <Arduino.h>

/* Return the incoming message as a char* */
char * readZB( char inMessage[] );
/* send to zigbee radio */
void sendZB( char printString[] );

/* reboot an inverter */
void inverterReboot(int which);

void resetValues(bool energy, bool mustSend);

String ECU_REVERSE();

void swap_to_usb();

#endif