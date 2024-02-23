/*
 * This is a demonstration of how to use the WiFiConfigurator library for ESP32 & ESP8266.
 * The library provides an easy way to configure WiFi connections with the help of WiFiManager.
 * In this example, we initialize the WiFi configuration in the setup function and
 * check if the configuration needs to be saved in the loop function.
 * This is for using Blynk IoT Cloud using ESP8266 and AHT20 I2C Sensor.
 * This library is developed by Shakaut Hossain (https://github.com/shakauthossain)
 * Download the library from the link - ********************


  **********************************************************************************************************
  *                                                                                                        *
  *       In ESP32 or ESP8266, We need to call for saveral libraries like WiFi.h or ESP32WiFi and to       *
  *         manage it we need to write 10-15 lines of code but here we can just call one library           *
  *                 with 4 more line and it will connect the WiFi from anywhere.                           *
  *                                                                                                        *
  *                                    Developed By Shakaut Hossain                                        *
  *                                                                                                        *
  **********************************************************************************************************

*/

// Define Blynk template ID, name, and authentication token
#define BLYNK_TEMPLATE_ID "Your_Temp_ID_From_Blynk"
#define BLYNK_TEMPLATE_NAME "Your_Temp_Name_From_Blynk"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token_From_Blynk"

// Include necessary libraries
#include <WiFiConfigurator.h>
#include <Adafruit_AHTX0.h>
#include <BlynkSimpleEsp32.h>

// Initialize WiFiConfigurator, AHTX0 sensor, and BlynkTimer
WiFiConfigurator wifiConfigurator;
Adafruit_AHTX0 aht;
BlynkTimer timer;

void setup() {
  // Setup WiFi configuration portal
  wifiConfigurator.setup();
  
  // Configure Blynk with authentication token
  Blynk.config(BLYNK_AUTH_TOKEN);
  
  // Start serial communication
  Serial.begin(115200);
  Serial.println("Adafruit AHT10/AHT20 demo!");

  // Initialize AHTX0 sensor
  if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10); // Endless loop if sensor is not found
  }
  Serial.println("AHT10 or AHT20 found");
}

void loop() {
  // Check if WiFi configuration needs to be saved
  if (wifiConfigurator.shouldSaveConfiguration()) {
    wifiConfigurator.resetSaveFlag();
  }
  
  // Run Blynk tasks
  Blynk.run();
  
  // Read temperature and humidity from AHTX0 sensor
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
  
  // Send temperature and humidity values to Blynk
  Blynk.virtualWrite(V0, temp.temperature); // Sending temperature value to virtual pin V0
  Blynk.virtualWrite(V1, humidity.relative_humidity); // Sending humidity value to virtual pin V1

  delay(500); // Delay before next sensor reading
}
