#define S1_Red_Led 13
#define S1_Yellow_Led 12
#define S1_Green_Led 11

#define S2_Red_Led 7
#define S2_Yellow_Led 6
#define S2_Green_Led 5


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(S1_Red_Led, OUTPUT);
  pinMode(S1_Yellow_Led, OUTPUT);
  pinMode(S1_Green_Led, OUTPUT);
  
  pinMode(S2_Red_Led, OUTPUT);
  pinMode(S2_Yellow_Led, OUTPUT);
  pinMode(S2_Green_Led, OUTPUT);
  
  digitalWrite(S1_Red_Led, HIGH);
  digitalWrite(S1_Yellow_Led, LOW);
  digitalWrite(S1_Green_Led, LOW);
  
  digitalWrite(S2_Red_Led, HIGH);
  digitalWrite(S2_Yellow_Led, LOW);
  digitalWrite(S2_Green_Led, LOW);

}

// the loop routine runs over and over again forever:
void loop() {
  
  // Control the Semaphore 

  digitalWrite(S1_Red_Led, HIGH);
  delay(1000);
  digitalWrite(S2_Red_Led, LOW);

  digitalWrite(S2_Green_Led, HIGH);
  delay(4000);
  
  digitalWrite(S2_Green_Led, LOW);
  digitalWrite(S2_Yellow_Led, HIGH);
  delay(2000);
  digitalWrite(S2_Yellow_Led, LOW);

  digitalWrite(S2_Red_Led, HIGH);
  delay(1000);
  digitalWrite(S1_Red_Led, LOW);
  digitalWrite(S1_Green_Led, HIGH);
  delay(4000);
  
  digitalWrite(S1_Green_Led, LOW);
  digitalWrite(S1_Yellow_Led, HIGH);
  delay(2000);
  digitalWrite(S1_Yellow_Led, LOW);
  
}
