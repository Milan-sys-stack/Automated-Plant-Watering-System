#include "thingProperties.h"
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

int moistPin = A6;
String waterPumpState;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  //Get Cloud Info/errors , 0 (only errors) up to 4
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  //Wait to get cloud connection to init the carrier
  while (ArduinoCloud.connected() != 1) {
    ArduinoCloud.update();
    delay(500);
  }

  delay(500);
  CARRIER_CASE = false;
  carrier.begin();
  carrier.display.setRotation(0);
  delay(1500);
}

void loop() {
  //Update the Cloud
  ArduinoCloud.update();


  //read raw moisture value
  int raw_moisture = analogRead(moistPin);

  //map raw moisture to a scale of 0 - 100
  moisture = map(raw_moisture, 0, 1023, 100, 0);


}


void onWaterpumpChange() {
  if (waterpump == true) {
    carrier.Relay1.open();
    waterPumpState = "PUMP: ON";
  } else {
    carrier.Relay1.close();
    waterPumpState = "PUMP: OFF";
  }
  updateScreen();
}




//Update displayed Info
void updateScreen() {
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.setTextSize(3);

  carrier.display.setCursor(40, 50);
  carrier.display.print(waterPumpState);

}

