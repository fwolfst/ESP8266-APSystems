#ifndef EXTERNAL_H
#define EXTERNAL_H

#include <Arduino.h>

// find out if the request comes from inside the network
//check if the first 9 characters of the router's ip ( 192.168.0 ) is in the url
bool checkRemote(String url) ;

void handleNotFound(AsyncWebServerRequest * request);

#endif