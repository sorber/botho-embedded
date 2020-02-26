
 
int led = 12;
int oldx, oldy, oldz;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  Serial.begin(9600);    
}

// the loop routine runs over and over again forever:
void loop() {
  int lightLevel = analogRead(A5);
  int x = analogRead(A4);
  int y = analogRead(A3);
  int z = analogRead(A2);
  int button = digitalRead(2);
  

  //Serial.println(lightLevel);
  Serial.print(button);
  Serial.print(",");
  Serial.print(x-oldx);
  Serial.print(",");
  Serial.print(y-oldy);
  Serial.print(",");
  Serial.println(z-oldz);
  

  //if (lightLevel < 500) {
  if (oldx-x > 30) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(20);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(20);               // wait for a second
  } else {
    delay(10);
  }
  oldx = x;
  oldy = y;
  oldz = z;
}
