#include <SoftwareSerial.h>

// Program Variables

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

#define sio      6           // ColorPAL connected to pin 6
#define unused   255         // Non-existant pin # for SoftwareSerial
#define sioBaud  4800        // Software Serial baudrate

// Received RGB values from ColorPAL
int red;
int grn;
int blu;

// Set up two software serials on the same pin.
SoftwareSerial serin(sio, unused);
SoftwareSerial serout(unused, sio);


// Reset ColorPAL using documentation sequence
void reset() {
  delay(200);
  pinMode(sio, OUTPUT);
  digitalWrite(sio, LOW);
  pinMode(sio, INPUT);
  while (digitalRead(sio) != HIGH);
  pinMode(sio, OUTPUT);
  digitalWrite(sio, LOW);
  delay(80);
  pinMode(sio, INPUT);
  delay(200);
}

void readData() {
  char buffer[32];
 
  if (serin.available() > 0) {
    // Wait for a $ character, then read three 3 digit hex numbers
    buffer[0] = serin.read();
    if (buffer[0] == '$') {
      for(int i = 0; i < 9; i++) {
        while (serin.available() == 0);     // Wait for next input character
        buffer[i] = serin.read();
        if (buffer[i] == '$')               // Return early if $ character encountered
          return;
      }
      parseAndPrint(buffer);
    }
  }
}

// Parse the hex data into integers
void parseAndPrint(char * data) {
  sscanf (data, "%3x%3x%3x", &red, &grn, &blu);  // Pull the R, G, and B values from the data string
  
  char buffer[48];                               // create a buffer
  sprintf(buffer, "r = %4.4d    g = %4.4d    b = %4.4d", red, grn, blu);   //print the values into a buffer as formatted integers
  Serial.println(buffer);
}


void setup() {
	
	 ////////////////////////////
	 // Setup Ultrasonic Sensor
	 ////////////////////////////
	 
	 pinMode(trigPin, OUTPUT);   // Sets the trigPin as an Output
	 pinMode(echoPin, INPUT);    // Sets the echoPin as an Input
	
	 ///////////////////////////
	 // Setup Colorpal
	 //////////////////////////
	 
	 delay(2000);			     // Set a delay

	 Serial.begin(9600);		 // Start serial communication
	 reset();                    // Send reset to ColorPal
	 
	 serout.begin(sioBaud);      // Start softSerial at sioBaud rate
	 pinMode(sio, OUTPUT);       // set Software serial pin an output pin
	 
	 serout.print("=(00 $ m)!"); // Loop print values, see ColorPAL documentation
	 serout.end();               // Discontinue serial port for transmitting
	 
	 pinMode(sio, INPUT);		 // Set software serial pin as an input pin
	 serin.begin(sioBaud);       // Set up serial port for receiving
}

void loop() {
	// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	
	// Calculating the distance
	distance= duration*0.034/2;
	
	// keep ultrasonic distance below 15
	if (distance > 15)
	{
		distance = 15;
	}
	
	for (int x = 0; x<= 10; x += 5)
	{
		// Read and print Ultrasonic Sensor Data to serial port
		//Serial.println(distance);
	}
	
	
	// Read and print Colorpal sensor data
	readData();
	
	delay(10);
}


