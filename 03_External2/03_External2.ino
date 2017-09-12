// pins
int redLEDPin   = 9;
int greenLEDPin = 10;

// delay
int redOnTime    = 250;
int redOffTime   = 250;
int greenOnTime  = 250;
int greenOffTime = 250;

// loop time
int redBlinkTime	= 2;
int greenBlinkTime  = 3;


void setup()
{
	// set LED pins as outputs
	pinMode(redLEDPin,   OUTPUT);
	pinMode(greenLEDPin, OUTPUT);
}

void loop()
{
	
	for(int i = 0; i <= redBlinkTime; i++)
	{
		// red LED on
		digitalWrite(redLEDPin, HIGH);
	
		// on time
		delay(redOnTime);
	
		// red LED off
		digitalWrite(redLEDPin, LOW);
	
		// off time
		delay(redOffTime);
	}
	
	for(int i = 0; i <= greenBlinkTime; i++)
	{
		// green LED on
		digitalWrite(greenLEDPin, HIGH);
			
		// on time
		delay(greenOnTime);
			
		// green LED off
		digitalWrite(greenLEDPin, LOW);
			
		// off time
		delay(greenOffTime);
	}
	
	
}
