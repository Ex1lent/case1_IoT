#include "Arduino.h"
#include "vector"
#include "queue"
#define BTN1 4
#define BTN2 5
#define BTN3 18
#define BTN4 19
#define RELE 21
#define LDR 12

const int btn_pins[] = {BTN1, BTN2, BTN3, BTN4};
int btn_prev_states[] = {0, 0, 0, 0};
bool closed = true;
std::vector<int> valid_code = {1,2,3,4};
std::vector<int> code = {0,0,0,0};

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
  closed = false;
}

void doorClose(){
  digitalWrite(RELE, 0);
  closed = true;
}

void checkBtn(int index){
  int read = !digitalRead(btn_pins[index]);
  if (read == 0 && btn_prev_states[index] == 1){
    btn_prev_states[index] = 0;
  }
  if (read == 1 && btn_prev_states[index] == 0){
    btn_prev_states[index] = 1;
    // Serial.print(index);
    // Serial.println(" - true");
    code.erase(code.begin());
    code.push_back(index+1);
  }
}

void loop() {
  int ldrValue = analogRead(LDR);
  for (int i = 0; i < 4; i++) {
    checkBtn(i);
  }
  for(int i = 0; i < 4; i++){
    Serial.print(code[i]);
  }
  Serial.println();
  delay(100);
}