#include "M5Atom.h"

void setup() {
  M5.begin();
  Serial.begin(115200);

  Serial.println("PIR example: ");

  pinMode(21, INPUT);
}

void loop() {

  
  if(digitalRead(21)==1){

    Serial.println("PIR Status: Sensing");
    Serial.println(" value: 1");
  }
  else{

    Serial.println("PIR Status: Not Sensed");
    Serial.println(" value: 0");
  }
  delay(500);
  M5.update();
}
