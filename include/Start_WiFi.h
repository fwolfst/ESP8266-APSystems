#ifndef START_WIFI_H
#define START_WIFI_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

void checkFixed();
void loginBoth(AsyncWebServerRequest *request, String who);

#endif