#define button 2
#define led1 3
#define led2 4
#define led3 5
#define led4 6

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  
  if (digitalRead(button) == LOW) {
    
    digitalWrite(led4, HIGH);
    delay(500);                   
    digitalWrite(led4, LOW);
    delay(500);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);                   
    digitalWrite(led2, LOW);
    delay(500);
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
    digitalWrite(led4, HIGH);
    delay(500);
    digitalWrite(led4, LOW);
    delay(500);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
    delay(500);
  }
}