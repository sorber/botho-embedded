/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
int led = 12;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  Serial.begin(9600);    
}

// the loop routine runs over and over again forever:
void loop() {
  int lightLevel = analogRead(A5);

  Serial.println(lightLevel);

  if (lightLevel < 500) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(100);               // wait for a second
  } else {
    delay(100);
  }
}
