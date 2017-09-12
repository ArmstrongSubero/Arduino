//SDA - A4
//SCL - A5

 /*
 float tempC = myPressure.readTemp();
 Serial.print(" Temp(c):");
 Serial.print(tempC, 2);
 */
  
 /*
 float altitude = myPressure.readAltitude();
 Serial.print("Altitude(m):");
 Serial.print(altitude, 2);
 */
 
 /*
 altitude = myPressure.readAltitudeFt();
 Serial.print(" Altitude(ft):");
 Serial.print(altitude, 2);
 */


#include <Wire.h>
#include "SparkFunMPL3115A2.h"

//Create an instance of the object
MPL3115A2 myPressure;

float tempC;
float tempF;
float pressure;

void setup()
{
  Wire.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output

  myPressure.begin(); // Get sensor online

  // Configure the sensor
  //myPressure.setModeAltimeter(); // Measure altitude above sea level in meters
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  
  myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
}

void loop()
{
 
  float pressure = myPressure.readPressure();
  Serial.print("Pressure(Pa):");
  Serial.print(pressure, 2);

  tempF = myPressure.readTempF();
  Serial.print(" Temp(f):");
  Serial.print(tempF, 2);

  Serial.println();
}