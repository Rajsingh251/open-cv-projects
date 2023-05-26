#include "Servo.h"
int incomingByte = 0;
int num;
Servo myservo;
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 char sdata[3];
 if (Serial.available()>0){
  incomingByte = Serial.readBytes(sdata,3); 
  int d1 = sdata[0]-'0';
  int d2 = sdata[1]-'0';
  int d3 = sdata[2]-'0';


  if(d3!=-38){
  int num = d1*100  +  d2*10  +  d3;
  if (num>0){
  Serial.println(num);
  pos = map(num,100,105,0,170);
  myservo.write(pos);
    if(num==101){        // switch case can be used
      digitalWrite(3,1);
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
    }
    else if(num==102){
      digitalWrite(3,1);
      digitalWrite(4,1);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);      
    }
    else if(num==103){
      digitalWrite(3,1);
      digitalWrite(4,1);
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(7,0);      
    }
    else if(num==104){
      digitalWrite(3,1);
      digitalWrite(4,1);
      digitalWrite(5,1);
      digitalWrite(6,1);
      digitalWrite(7,0);      
    }
    else if(num==105){
      digitalWrite(3,1);
      digitalWrite(4,1);
      digitalWrite(5,1);
      digitalWrite(6,1);
      digitalWrite(7,1);      
    }    
   else{
      digitalWrite(3,0);
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);   
   }
  }
  }
 }
}
