#include "Arduino.h"
#define BTN1 4
#define BTN2 5
#define BTN3 18
#define BTN4 19
#define RELE 21
#define LDR 12

void setup() {
  Serial.begin(9600);
  pinMode(BTN1, INPUT_PULLDOWN);
  pinMode(BTN2, INPUT_PULLDOWN);
  pinMode(BTN3, INPUT_PULLDOWN);
  pinMode(BTN4, INPUT_PULLDOWN);
  pinMode(RELE, OUTPUT);
  pinMode(LDR, INPUT);
}

void doorOpen(){
  digitalWrite(RELE, 1);
}

void doorClose(){
  digitalWrite(RELE, 0);
}

void loop() {
  int ldrValue = analogRead(LDR);
  if (ldrValue > 1500){
    doorClose();
  } else {
    doorOpen();
  }
  delay(100);
}