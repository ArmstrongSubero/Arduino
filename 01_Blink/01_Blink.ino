int LEDPin = 13;
int WaitTime = 1000;

void setup()
{
	pinMode(LEDPin, OUTPUT);
}

void loop()
{
	digitalWrite(LEDPin, HIGH);
	delay(WaitTime);
	digitalWrite(LEDPin, LOW);
	delay(WaitTime);
}
