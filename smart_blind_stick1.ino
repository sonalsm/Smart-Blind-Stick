
int value=0;
int Front = 0;
int Ground= 0;
void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
   pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
}

void loop()
  
{
  
  value= analogRead(A0);
  
  if(value<10)
  {
    digitalWrite(11, HIGH);
    Serial.println("Light ON");
    Serial.println(value);
  }
  else
  {
     digitalWrite(11, LOW);
    Serial.println("Light OFF");
    Serial.println(value);
  }
Front = 0.01723 * readUltrasonicDistance(5, 5);
  Serial.println(Front);
  if (Front < 60) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  Ground = 0.01723 * readUltrasonicDistance(6, 6);
  Serial.println(Ground);
  if (Ground < 60) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}