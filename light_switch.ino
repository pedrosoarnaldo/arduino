#define button 10
#define led 12


int vliga = LOW;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(led, vliga);
}

// the loop routine runs over and over again forever:
void loop() {

  if (digitalRead(button) == LOW) {
    
    
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(4000);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
  
}
