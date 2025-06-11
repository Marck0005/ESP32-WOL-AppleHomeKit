# ESP32-WOL-AppleHomekit

Integration of ESP32 with apple homekit

> [!WARNING]  
> This project requires a credential file with the WiFi network SSID and the MAC Addres of the target PC.
> The below example shows an example of this file.

```cpp
#pragma once

#define WIFI_SSID_PROJECT     "WiFi_SSID"
#define WIFI_PASSWORD_PROJECT "WiFi_Pass"
#define MAC_PROJECT           { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } // (PC_MAC)
