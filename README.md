Watering System with Arduino MKR IoT Carrier


This project is an example of a water irrigation system using an Arduino MKR IoT Carrier. It connects to the Arduino IoT Cloud, reads moisture levels from a sensor, and controls a water pump accordingly.

Table of Contents
Prerequisites
Hardware Setup
Software Setup
Usage
Code Explanation
License
Prerequisites
Before using this code, make sure you have the following:

An Arduino MKR IoT Carrier board.
Arduino IDE installed on your computer.
An active Arduino IoT Cloud account.
Hardware Setup
Connect a moisture sensor to analog pin A6.
Connect a water pump to the relay output on the MKR IoT Carrier.
Ensure the MKR IoT Carrier is properly connected to the Arduino board.
Software Setup
Install the required libraries.
Create a new device on the Arduino IoT Cloud.
Modify thingProperties.h to match your IoT Cloud properties.
Upload the code to your Arduino board.
Usage
Once the code is uploaded to the Arduino board, it will connect to the Arduino IoT Cloud.
The code reads moisture levels and adjusts the water pump state accordingly.
The water pump's state is displayed on the MKR IoT Carrier's screen.
Code Explanation
moistPin: Defines the analog pin for reading moisture levels.
waterPumpState: Stores the state of the water pump.
In the setup() function:

Serial communication is initialized.
IoT Cloud is set up and connected.
MKR IoT Carrier is initialized.
In the loop() function:

The code continuously updates the IoT Cloud and reads moisture levels.
The onWaterpumpChange() function:

Controls the water pump state based on IoT Cloud input.
Updates the waterPumpState variable.
The updateScreen() function:

Updates the information displayed on the MKR IoT Carrier's screen.
