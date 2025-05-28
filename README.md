# WARNING

Este proyecto requiere un archivo de credenciales para conectarse a una red WiFi y utilizar una dirección MAC específica.
This project requires a credential file with the WiFi network SSID and the MAC Addres of the target PC

## It should look like this:

```cpp
#pragma once

#define WIFI_SSID_PROJECT     "WiFi_SSID"
#define WIFI_PASSWORD_PROJECT "WiFi_Pass"
#define MAC_PROJECT           { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } // (PC_MAC)
