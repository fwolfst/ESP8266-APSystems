#ifndef CONFIG_IP_H
#define CONFIG_IP_H

#include <ESPAsyncWebServer.h>

void zendPageIPconfig();
void handleIPconfig(AsyncWebServerRequest * request);

#endif