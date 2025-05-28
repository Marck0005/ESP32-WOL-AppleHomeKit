#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <WakeOnLan.h>
#include <ESP32Ping.h>
#include "HomeSpan.h"
#include "credentials.h"

// WiFi
const char *ssid = WIFI_SSID_PROJECT;
const char *password = WIFI_PASSWORD_PROJECT;

// MAC of your PC
uint8_t pcMac[] = MAC_PROJECT;

// UDP and WakeOnLan objects
WiFiUDP UDP;
WakeOnLan WOL(UDP);

////////////////////////
//  HomeKit Service  //
struct WakePC : Service::Television
{

  SpanCharacteristic *power;

  WakePC() : Service::Television()
  {
    power = new Characteristic::On();
  }


  boolean update()
  {
    if (power->getNewVal())
    {
      Serial.println("🔔 Sending Magic Packet WOL...");
      WOL.sendMagicPacket(pcMac, sizeof(pcMac));
      Serial.println("📡 Magic Packet sent.");
    }
    return true;
  }
};
////////////////////////

void setup()
{
  Serial.begin(115200);
  delay(1000);

  // WiFi connetion
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected");

  WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());

  // HomeSpan parameters
  homeSpan.setPairingCode("11122333");
  homeSpan.begin(Category::Television, "My PC");

  // HomeKit setup
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new WakePC();
}

void loop()
{
  homeSpan.poll();
}
