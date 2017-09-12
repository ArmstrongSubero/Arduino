// global variables
int redLED  = 9;
int onTime  = 900;
int offTime = 100;

void setup()
{
	pinMode(redLED, OUTPUT);
}

void loop()
{

  digitalWrite(redLED, HIGH);
  delay(onTime);
  digitalWrite(redLED, LOW);
  delay(offTime);
}
