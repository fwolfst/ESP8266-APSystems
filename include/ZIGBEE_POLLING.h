#ifndef ZIGBEE_POLLING_H
#define ZIGBEE_POLLING_H

/* Wait a certain time to see if there is something available */
bool waitSerialAvailable(); // wait untill something 's available

void polling(int which);

#endif