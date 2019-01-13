#include <Servo.h> 

Servo servo1;
//Servo servo2;
int echoPin=A3;
int trigPin=A2;
//float Distance;
int i=0;
bool x = false;

float distance()
{
  float Distance=0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float Fdistance=pulseIn(echoPin, HIGH);
  Fdistance=Fdistance/5.8/10;
  Distance=Fdistance;
  return Distance;
}

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
//Serial.print("Hello World");
servo1.attach(3);
//servo2.attach(3);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.print("Hello World");
  do {
  float dist = distance();
//  Serial.print(dist);
  while (dist < 10.0) {
    for (i=0;i<=5; i+=1){
      servo1.write(i);
      if (dist> 10.0){
        break;
      }
  //    servo1.write(0);             
     delay(1);
     dist = distance();                   
    }       
  }
//   (dist > 10.0){                                
        servo1.write(0);         
        delay(1);  
//      }
  }
  while (x = true);
}
