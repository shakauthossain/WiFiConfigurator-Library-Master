#ifndef WiFiConfigurator_h
#define WiFiConfigurator_h

#include <Arduino.h>
#include <WiFiManager.h>

class WiFiConfigurator {
private:
    WiFiManager wifiManager;
    bool shouldSaveConfig = false;

public:
    WiFiConfigurator();
    void setup();
    bool shouldSaveConfiguration();
    void resetSaveFlag();
};

#endif
