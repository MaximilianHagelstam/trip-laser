const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;

long duration;
int distance;
int safetyDistance;


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;
  
  safetyDistance = distance;
  
  if (safetyDistance <= 100)
  {
    tone(buzzer, 1000);
    delay(250);
    noTone(buzzer);
    tone(buzzer, 500);
    delay(250);
    noTone(buzzer);
  }
  
  else
  {
    noTone(buzzer);
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
}
