// Include servo library
#include <Servo.h>


// declare and init servo vars
int pos;
int servoPin = 9;
int servoDelay = 25;

// vars for pot
int potPin = A0;
int potReading;

// create servo object
Servo myServo;

void setup()
{
	// begin serial
	Serial.begin(9600);
	
	// attach servo object to servoPin
	myServo.attach(servoPin);
}

void loop()
{
	/*
	for(pos = 20; pos <= 165; pos++)
	{
		myServo.write(pos);    // send servo to pos
		delay(servoDelay);	   // wait a little
	}
	
	for(pos = 165; pos >= 20; pos--)
	{
		myServo.write(pos);	   // send servo to pos
		delay(servoDelay);	   // wait a little
	}
	*/
	
	potReading = analogRead(potPin);
	
	pos = (155.0/1023.0) * potReading + 15;
	myServo.write(pos);
}
