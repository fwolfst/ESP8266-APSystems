#ifndef ESP_ECU_H
#define ESP_ECU_H

// ZIGBEE
#define CC2530_MAX_SERIAL_BUFFER_SIZE 512

// APP
#define MAX_NUMBER_OF_INVERTERS 9

typedef struct{
  char invLocation[13] = "N/A";
  char invSerial[13]   = "000000000000";
  char invID[5]        = "0000";
  int  invType         = 0;
  int  invIdx          = 0;
  bool conPanels[4]    = {true,true,true,true};
} inverters; 

typedef struct{ 
  float freq = 0.0;
  float sigQ = 0.0;
  float heath = 0.0;
  float acv = 0.0;
  float dcc[4] = {0.0, 0.0, 0.0, 0.0};              // ampere <100 
  float dcv[4] = {0.0, 0.0, 0.0, 0.0};              // volt <100
  float power[4] = {0.0, 0.0, 0.0, 0.0};       //watt < 1000
  float pw_total = 0.0;
  float en_total = 0;
} inverterdata;

#define LOG

#ifdef LOG
 typedef struct { // __cleanup__ : renamed fields to Log_ .
  char Log_date[14] ;
  int  Log_kind ; // zigbee, system, mqtt, pairing
  char  Log_message[13] ;
} logEvent;
#endif

#define Log_MaxEvents 18

// HARDWARE

void ledblink(int i, int wacht);
void empty_serial();

// ZIGBEE PINS
#define ZB_RESET          14 // D5
#define ZB_TX             15 // D8

// Something, somewhere, somewhat

void eventSend(byte what);


#endif