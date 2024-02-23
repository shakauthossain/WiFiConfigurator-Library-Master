/*
 * This is a demonstration of how to use the WiFiConfigurator library for ESP32 & ESP8266.
 * The library provides an easy way to configure WiFi connections with the help of WiFiManager.
 * In this example, we initialize the WiFi configuration in the setup function and
 * check if the configuration needs to be saved in the loop function.
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

#include <WiFiConfigurator.h>                 //Download the library from ******************

WiFiConfigurator wifiConfigurator;            // Create an instance of the WiFiConfigurator class

void setup() {
  wifiConfigurator.setup();                   //setup function will make the ESP8266 as an AP Point to take WiFi credentials to connect it with your WiFi
  
  //Your Main Code Here
}

void loop() {
  // Check if configuration needs to be saved
  if (wifiConfigurator.shouldSaveConfiguration()) {
      wifiConfigurator.resetSaveFlag();       //If the credentials of WiFi is not saved before it will start to make the AP or it will connect to the WiFi automatic
  }
  
  //Your Main Code Here

}