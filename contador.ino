etup() {
  // initialize the digital pin as an output.
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);

}

//         7c1
//         --
//  13c5 |    | 8c2
//  10c6   -- 
//  11c7 |    | 9c3
//         --
//        12c4

int i=0;
boolean c1,c2,c3,c4,c5,c6,c7=LOW;

void zeraVariaveis() {
  c1=c2=c3=c4=c5=c6=c7=LOW;
}

void acendeLeds() {
   digitalWrite(13, c5);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(12, c4);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(11, c7);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(10, c6);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(9, c3);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(8, c2);   // turn the LED on (HIGH is the voltage level)
   digitalWrite(7, c1);   // turn the LED on (HIGH is the voltage level)
}

// the loop routine runs over and over again forever:
void loop() {
  for (i=0;i<10;i++) {
    zeraVariaveis();
    switch(i) {
      case 0:
        c1=c2=c3=c4=c4=c5=c7=HIGH;
        break;
      case 1:
        c2=c3=HIGH;
        break;
      case 2:
        c1=c2=c6=c7=c4=HIGH;
        break;
      case 3:
        c1=c2=c6=c3=c4=HIGH;
        break;
      case 4:
        c5=c6=c2=c3=HIGH;
        break;
      case 5:
        c1=c5=c6=c3=c4=HIGH;
        break;
      case 6:
        c1=c5=c6=c3=c4=c7=HIGH;
        break;
      case 7:
        c1=c2=c3=HIGH;
        break;
      case 8:
        c1=c2=c3=c4=c5=c6=c7=HIGH;
        break;
      case 9:
        c1=c2=c5=c6=c3=HIGH;
        break;
    }
  acendeLeds();
  delay(1000);
  }
}
