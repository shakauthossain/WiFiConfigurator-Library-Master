#include "WiFiConfigurator.h"

WiFiConfigurator::WiFiConfigurator() {
    // Setup callback for configuration save
    wifiManager.setSaveConfigCallback([&]() {
        Serial.println("Should save config");
        shouldSaveConfig = true;
    });
}

void WiFiConfigurator::setup() {
    // Set WiFi mode to station mode
    WiFi.mode(WIFI_STA);

    Serial.begin(115200);

    // Attempt to connect to WiFi or start configuration portal
    bool res = wifiManager.autoConnect("ESP Manual WiFi"); // Create an anonymous access point

    if (!res) {
        Serial.println("Failed to connect");
        // Consider restarting the ESP or implementing error handling
        // ESP.restart();
    } else {
        Serial.println("Connected Successfully - Thanks to THE EMBEDDEX HEX");
    }
}

bool WiFiConfigurator::shouldSaveConfiguration() {
    return shouldSaveConfig;
}

void WiFiConfigurator::resetSaveFlag() {
    shouldSaveConfig = false;
    
}
