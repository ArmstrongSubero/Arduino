// setup trigger and echo pins
int trigPin = 9;
int echoPin = 10;

// time for ping to hit target and return
float pingTime;

// declare vars to calculate speed of sound
float speedOfSound;
float targetDistance = 6;
float metersSecond;
float kmHour;

void setup()
{
    // setup serial
	Serial.begin(9600);
	
	// setup pins
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop()
{
	////////////////////////////////
	//  Pulse
	///////////////////////////////
	
	// set trigger pin low
	digitalWrite(trigPin, LOW);
	
	// delay 2 ms to let signal settle
	delayMicroseconds(2000);
	
	// set trigger pin high
	digitalWrite(trigPin, HIGH);
	
	// pause with trigger pin high
	delayMicroseconds(10);
	
	// finish pulse
	digitalWrite(trigPin, LOW);
	
	///////////////////////////////
	// Measure Ping
	//////////////////////////////
	
	// measure ping traveled time in microseconds
	pingTime = pulseIn(echoPin, HIGH);
	
	// speed in cm/us
	speedOfSound = (2 * targetDistance)/pingTime;
	
	// convert to m/s
	metersSecond = speedOfSound * 10000;
	
	// convert to km/hr
	kmHour = metersSecond * 3.6;
	
	// print result
	Serial.print("The speed of sound is: ");
	Serial.println(kmHour);
	Serial.println(" km/hr");
	
	// delay 3 seconds
	delay(3000);
}
