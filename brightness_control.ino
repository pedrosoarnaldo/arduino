int led = 8;
int pot = 5;
int val;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH); 
  val = analogRead(pot);
  Serial.println(val);
}
