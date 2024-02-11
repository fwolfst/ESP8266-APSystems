# ECU-ESP8266

Experimental fork of [@patience4711](https://github.com/patience4711)s [read-APSystems-YC600-QS1-DS3](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/) project to read sun harvest data out of an APSystems inverter (solar power).

The goal is to make it reproducibly compile with [platformIO](platformio.org) instead of the ArduinoIDE used by the original author.
Targetted microcontroller is the ESP8266, build system is acd  Debian 12.

For a blank slate implementation that does not pair yet :( see [ECU-ESP8266](https://github.com/fwolfst/ECU-ESP8266).

## Lessons learnt and thoughts not finished

- My C and C++ skills are rusty (at best).
- Project layout/ app architecture for an embedded system puts different
  spotlights then when building a web application with Ruby on Rails.
- Still not sure about the trade-off between global state and e.g. buffers and
  local variables.
- I am ditching vim for platformio here, but lets see how long it'll last.
- Will need to look into general and especially embedded conventions, e.g. https://barrgroup.com/embedded-systems/books/embedded-c-coding-standard . Or GNU/Linux or GTK...
- `SoftwareSerial` might help in developing and debugging (currently we throw away our possibility to debug to Serial, because that is remapped to the zigbee module). Or use `Serial1`?

## License and Copyright

[Unclear to me, but we are allowed to
hack](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/issues/105).

# Original README

# read APS inverters
The purpose of this project is to read data via Zigbee from APS Systems inverters. The program can pair and poll YC600 QS1 and DS3(-L-M-S verified) inverters, up to 9 pieces. The read values are displayed on a web page and sent via mosquitto in a user-defined Json format.
The program has a lot of smart features. All settings can be done via the webinterface. It has a console that can be used for debugging and sending/receiving zigbee messages.<br>
See the <a href='https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/wiki'>WIKI</a> for information on building it, the working, etc. 

See it in action on [YouTube](https://youtu.be/WKFVQ6d8KhQ)

This program runs on different platforms, there is [ESP32-ECU](https://github.com/patience4711/ESP32-read-APS-inverters) and [RPI-ECU](https://github.com/patience4711/RPI-APS-inverters) that runs on a Raspberry (Zero). Each have its advantages over the others. If you have many inverters you are probably better off with the ESP32 or Raspberry implementation.

## compile this sketch
You can use the provided binary but if you must compile it yourself: Use arduino ide with the esp822 version 2.7.1 installed under boardmanager. The ota updates won't work with other versons.
<br>Please note: by popular demand I have published the code here but i do not feel responsible for problems as to compiling. Impossible for me to know why it doesn't compile in your situation.

## downloads
july 26 2023: There is a new version 10_8 available, see changelog,<br> 
Download [ESP-ECU-v10_8](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/blob/main/ESP-ECU-v10_8.bin)<br>

july 30 2023: There is package available with all necessary files, like software for the zigbee, a serial communicater etc.<br>
Download [ESP-ECU-ADDON](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/blob/main/ESP-ECU_ADDON.zip)<br>

Download the zigbee firmware [CC25XX-FIRMWARE](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/blob/main/CC25xx-FIRMWARE.zip)

<br>In case someone wants to print the housing, here is an [stl file](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/blob/main/ESP-ECU-housing.zip)
This is for a nodemcu board 31x58mm.

## features
- Simply to connect to your wifi
- Easy add, delete and pair inverters
- automatic polling or on demand via mqtt or http
- data can be requested via http and mosquitto
- There are 4 different mqtt json formats
- Fast asyc webserver
- a very smart on-line console to send commands and debugging
- Smart timekeeping
- A lot of system info on the webpage

## the hardware
It is nothing more than an esp device like nodemcu, wemos or its relatives and a prepared cc2530, cc2531 zigbee module. And a powersupply.
The zigbeemodule should be flashed with a firmware that is developped by kadsol : [CC25xx_firmware](https://github.com/Koenkk/zigbee2mqtt/files/10193677/discord-09-12-2022.zip). The firmware is also available [here](https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/blob/main/cc25xx_firmware.zip). Much more info as to the development of this software can be found here https://github.com/Koenkk/zigbee2mqtt/issues/4221. 

For info on how to build and use it, please see the <a href='https://github.com/patience4711/read-APSystems-YC600-QS1-DS3/wiki'>WIKI</a>

![minhw](https://user-images.githubusercontent.com/12282915/138685751-98112dfd-8ed8-4185-9de7-c2e2e8f005a9.jpg)
## how does it work
APS works with their own zigbee implementation. The ESP-ECU sends zigbee commands (wireless) to the inverters and analyzes the answers, extracting the values. 
The ESP communicates with the zigbee module through the alternative serial port (wired).
The ESP-ECU starts a coordinator (an entity that can start a zigbee network). The coordinator binds the inverters and sends the poll requests to them.
The interesting values are send via mqtt and displayed on the main page.

![front](https://user-images.githubusercontent.com/12282915/233657814-5f8aa18a-aff9-4668-9dec-7d6cc55f6f1c.jpg)

![graph2](https://user-images.githubusercontent.com/12282915/139062602-71e92216-9703-4fc4-acc6-fabf544c4ffd.jpg)

## changelog ##
version ESP-ECU_V10:
-  introduced a new way for communication webpage-server.
-  compressed web files.
-  Some cosmetic changes 

version ESP-ECU_V9_14:
-  improved efficiency in the data trafic browser-server.
-  tuned timing in the wifi config portal.

version ESP-ECU_V9_13b:
-  solved some bugs in the pairing process.
-  secured the system, prevent visiting the menu from outside own network

version ESP-ECU_V9_12:
-  completely re-designed "the engine", 40% more free heap.
-  Some cosmetic improvements

version ESP-ECU_V9_9:
- fix for the zigbee crashes
- improved frontpage with buttons to see details.
- fixed memory issues, more free heap.
- cleaned up and streamlined the code with help of @fwolfst

version ESP-ECU_V9_6c:
- fixed a typo in the help page of mosquitto settings
- added 2 mqtt json formats, numeric values are included as float now.
- added the retain flag to mqtt formats 3 and 4
- changed the format of the returned json when http request.
- added an option to have an mqtt topic for each inverter.
- some changes to improve the polling process
- added a forced zigbee reset every midnight.

version ESP-ECU_V9_5:
- added a mqtt command for polling all inverters
- added a signal quality value

version ESP-ECU_V9_4:
- fixed failed polling after power cycle
- fine-tuned some dc values of the DS3
- default conversion factor now 1.66
 
version ESP-ECU_V9_3:
- fixed a bug with a negative poll offset
- added the poll- begin and end time on the main page

version ESP-ECU_V9_2:
- made it suitable for the DS3 inverter.
- fixed polling intervall of 5 minutes.
- bug repaired, sq1 dc data panels 2 and 3

As of version 8 the value of total energy is no longer directly comming from the inverter's register. Instead all energy increases are added up in a total energy value. 
This way that value is not sensitive to inverter resets that will happen in twilight or due to an eclips etc.
