#ifndef MQTT_H
#define MQTT_H

bool mqttConnect();
void MQTT_Receive_Callback(char *topic, byte *payload, unsigned int length);

#endif