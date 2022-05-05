#pragma once

#include <Arduino.h>

#include <map>
#include <string>

#include "device/device.h"
#include "node/node.h"

#include <IRremoteESP8266.h>
#include <IRsend.h>

// Here are my NEC-format commands read from original TV remote control buttons
// You can get similar commands using IRremoteESP8266 library example `IRrecvDumpV2.ino` with Your own TV remote control
#define CHANNEL1_NEC 0xFB2AD5
#define CHANNEL2_NEC 0xFB6897
#define OK_NEC 0xFB609F
#define ONOFF_NEC 0xFB38C7
#define VOLUME_UP_NEC 0xFBD22D
#define VOLUME_DOWN_NEC 0xFBF20D

const uint16_t kIrLed = 4;  // ESP32 GPIO pin to use. Recommended: GPIO4.

class IRControl : public Node {
 public:
    IRControl(const char* name, const char* id, Device* device);
    bool Init(Homie* homie);
    void HandleCurrentState();
};
