#ifndef ZIGBEE_PAIR_H
#define ZIGBEE_PAIR_H

#include <ESPAsyncWebServer.h>

bool pairing(int which);
void pairOnActionflag();
void handlePair(AsyncWebServerRequest * request);

#endif