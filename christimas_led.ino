// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 13;
int led2 = 4;
int led3 = 3;
int led4 = 2;
int led5 = 1;
int pot = 0;
int val = 0;
  
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  val = analogRead(pot); 
  digitalWrite(led1, HIGH);
  delay(val);               
  digitalWrite(led1, LOW);    
  digitalWrite(led2,HIGH);
  delay(val);              
  digitalWrite(led2, LOW);    
  digitalWrite(led3,HIGH);
  delay(val);
  digitalWrite(led3, LOW);    
  digitalWrite(led4,HIGH);
  delay(val);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(val);
  digitalWrite(led5, LOW);
}
