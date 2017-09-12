//SDA - A4
//SCL - A5

#include <Wire.h>
#include "SparkFunMPL3115A2.h"

//Create an instance of the object
MPL3115A2 myPressure;

// variables for pressure and temperature
float tempF;
float pressure;

void setup()
{
  Wire.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output

  myPressure.begin(); // Get sensor online

  // Configure the sensor
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
}

void loop()
{
  // Read temperature
  tempF = myPressure.readTempF();
  Serial.print(tempF, 2);
  
  // Print comma
  Serial.print(" , ");
  
  // Read pressure
  float pressure = myPressure.readPressure();
  Serial.println(pressure, 2);
}