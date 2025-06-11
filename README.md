# ESP32-WOL-AppleHomekit

Integration of ESP32 with apple homekit to power on a PC via WIFI
using the apple home application.

> [!WARNING]  
> This project requires a credential file with the WiFi network SSID and the MAC Addres of the target PC.
> The below example shows an example of this file.

```cpp
#pragma once

#define WIFI_SSID_PROJECT     "WiFi_SSID"
#define WIFI_PASSWORD_PROJECT "WiFi_Pass"
#define MAC_PROJECT           { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } // (PC_MAC)
```

## Requirements
* The target PC must have "Wake On LAN" set in the BIOS.
* ESP32 must be in the same network as the PC.
* Router must be configured to admit broadcast UDP packets (which should be set by default)

## Troubleshooting
### WIFI CREDENTIALS NOT FOUND
If the device doesn't appear on the apple home app, and see the following output on the serial:
```bash
*** WIFI CREDENTIALS DATA NOT FOUND.  YOU MAY CONFIGURE BY TYPING 'W <RETURN>'.
```
You need to type uppercase 'W' and hit enter. Set the SSID and WIFI password afterwards and reset the ESP32.

### I deleted the device on the home app, but it doesn't appear anymore
That's because the ESP32 has stored the pairing device (your phone in this case).
To unpair it, just write uppercase 'H' on the serial and hit entre.