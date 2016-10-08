#include "Ultrasonic.h"

int state = 1;

Ultrasonic ultrasonic(12, 13); 

void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop(){
  
  
  if (Serial.available()){
    int val;
    val = Serial.read();
    if(val == 'R'){
      Serial.println("Run the machine");
      state = 1;
    }else if(val == 'S'){
      state = 0;
    }
  }
  
  if(state == 1){
    float dist_cm = ultrasonic.Ranging(CM);
    
    if(dist_cm > 200){
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
    }else{
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      delay(500); 
    }
    delay(100); 
  }
}
