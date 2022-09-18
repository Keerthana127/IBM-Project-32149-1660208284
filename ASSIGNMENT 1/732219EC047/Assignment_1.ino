int x,y;
double z,temp;
void setup()
{
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  x= digitalRead(8);
  y= analogRead(A5);
  z= analogRead(A4);
  
  Serial.print("PIR:");
  Serial.println(x);
  
  Serial.print("LDR:");
  Serial.println(y);
  
  temp = (((z / 1024) * 5) - 0.5) * 100;               
  Serial.print("TMP:");
  Serial.println(temp);
  if ( (x>0) )
  {
    if ((y<550)&&(temp>30))
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
    }
    else if((y<550)&&(temp<30))
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
    }
    else if((y>550)&&(temp>30))
    {
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
    }
    else if((y>550)&&(temp<30))
    {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }
    
    delay(10000);
  }
  
  else
  {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
