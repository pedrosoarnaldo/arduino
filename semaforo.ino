// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(13, HIGH);   // turn the RED LED on (HIGH is the voltage level)
  delay(4000);              // wait 4 seconds
  digitalWrite(13, LOW);    // turn the  RED LED off by making the voltage LOW
  digitalWrite(2, HIGH) ;   // turn the Green LED on (HIGH is the voltage level)
  delay(4000);              // wait 4 seconds
  digitalWrite(2, LOW);     // turn the Green LED off by making the voltage LOW
  digitalWrite(8, HIGH) ;   // turn the Yellow LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(8, LOW);     // turn the Yellow LED off by making the voltage LOW
}
