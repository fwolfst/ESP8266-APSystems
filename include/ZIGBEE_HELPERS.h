#ifndef ZIGBEE_HELPERS_H
#define ZIGBEE_HELPERS_H

/* Return the incoming message as a char* */
char * readZB( char inMessage[] );

/* reboot an inverter */
void inverterReboot(int which);
void basisConfigsave();

#endif