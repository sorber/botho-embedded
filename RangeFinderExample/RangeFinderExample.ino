#define trigPin 12
#define echoPin 13
#define red 11
#define green 10
#define blue 9

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void updateLed(int r, int g, int b) {
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; //convert pulse duration to cm
  
  if(distance < 10)
  {
    updateLed(255, 0, 0);
    delay(50);
    updateLed(0, 0, 0);
    delay(50);
  }
  if(distance>50 && distance <= 400)
  {
    updateLed(0, 255, 0);
    delay(150);
    updateLed(0, 0, 0);
    delay(150);
  }
  if(distance>10 && distance<50)
  {
    updateLed(255, 50, 0);
    delay(100);
    updateLed(0, 0, 0);
    delay(100);
  }
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(10);
}
