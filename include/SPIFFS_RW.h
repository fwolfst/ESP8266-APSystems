#ifndef SPIFFS_RW_H
#define SPIFFS_RW_H

#include <Arduino.h>

void writeStruct( String whichfile, int nummer);

void basisConfigsave();

void wifiConfigsave();

void mqttConfigsave();

void SPIFFS_read();

bool leesStruct(String whichfile);

#endif