#define button 10
#define led 12


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(led, LOW);
}

boolean vstatus=LOW;
// the loop routine runs over and over again forever:
void loop() {

if (digitalRead(button) == LOW) {

      delay(250);
      
      if (vstatus == LOW) {
        vstatus = HIGH;
      }
      else {
        vstatus = LOW;
      }
    digitalWrite(led, vstatus);   // turn the LED on (HIGH is the voltage level)
  }
  
}
