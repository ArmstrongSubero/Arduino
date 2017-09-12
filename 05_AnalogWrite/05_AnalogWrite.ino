
// PWM output PIN
int redLedPin = 9;

// PWM value
int pwmValue = 128;

void setup()
{
  // setup PIN for PWM
  pinMode(redLedPin, OUTPUT);

}

void loop()
{
  // write PWM value to PIN
  analogWrite(redLedPin, pwmValue);

}
