// declare serial string
String readyMsg = "Ready: ";
String sucessString = "You Entered: ";

int delayTime  = 1000;
int numRead;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
  // print ready message
  Serial.println(readyMsg);
  
  // 0 user hasn't entered number yet
  // do nothing
  while(Serial.available()==0);
  
  // read integer
  numRead = Serial.parseInt();
  
  // tell user integer entered
  Serial.print(sucessString);
  Serial.println(numRead);
  
  delay(delayTime);

}
