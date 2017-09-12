int cnt = 0;

void setup()
{

  Serial.begin(9600);

}

void loop()
{

  Serial.print("I am counting to: ");
  Serial.print(cnt);
  Serial.println(" Mississippi");
  
  cnt++;

  delay(1000);
}
