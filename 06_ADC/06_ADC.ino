// assign potPIN to A0
int potPin = A0;

// declare var to read value
int readValue;

void setup()
{
	pinMode(potPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	// read value from A0
	readValue = analogRead(potPin);
	
	// print via serial
	Serial.println(readValue);
	
	// delay 250 ms
	delay(250);
}
