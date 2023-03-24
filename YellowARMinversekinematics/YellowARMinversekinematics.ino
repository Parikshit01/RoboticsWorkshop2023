#include <Servo.h> 
Servo myservo1, myservo2, myservo3; 
int IN1=2; int IN2=4; int EN1=3; 
int value1=A0; int desiredangle1=60; 
int IN3=7; int IN4=8; int EN2=5; 
int value2=A1; int desiredangle2=60; 
int IN5=12; int IN6=13; int EN3=6; 
int value3=A2; int desiredangle3=60; 
int servo1pin=9; int servo2pin=10; int servo3pin=11; 
int gripperangle1=60; int analogfeedback1=A3; 
int gripperangle2=60; int analogfeedback2=A4; 
int gripperangle3=60; int analogfeedback3=A5; 

void setup() {

Serial.begin(9600); 
pinMode(IN1,OUTPUT); pinMode(IN2,OUTPUT); pinMode(value1,INPUT); 
pinMode(IN3,OUTPUT); pinMode(IN4,OUTPUT); pinMode(value2,INPUT); 
pinMode(IN5,OUTPUT); pinMode(IN6,OUTPUT); pinMode(value3,INPUT); 
myservo1.attach(servo1pin); pinMode(analogfeedback1,INPUT); 
myservo2.attach(servo2pin); pinMode(analogfeedback2,INPUT); 
myservo3.attach(servo3pin); pinMode(analogfeedback3,INPUT); 
} 

void loop() { 
int sensorvalue1=analogRead(value1); 
int sensorvalue2=analogRead(value2); 
int sensorvalue3=analogRead(value3); 
int sensorvalue4=analogRead(analogfeedback1); 
int sensorvalue5=analogRead(analogfeedback2); 
int sensorvalue6=analogRead(analogfeedback3); 
//Serial.println(sensorvalue1); 
int potvoltage1=map(sensorvalue1,0,1023,700,4600); 
int potvoltage2=map(sensorvalue2,0,1023,700,4600); 
int potvoltage3=map(sensorvalue3,0,1023,0,4700); 
int voltage4=map(sensorvalue4,109,463,550,2250); 
int voltage5=map(sensorvalue5,109,463,550,2250); 
int voltage6=map(sensorvalue6,109,463,550,2250); 
int presentangle1=map(potvoltage1,700,4600,0,270); 
int presentangle2=map(potvoltage2,700,4600,0,360); 
int presentangle3=map(potvoltage3,0,4700,0,360); 
int presentangle4=map(voltage4,550,2250,0,180); 
int presentangle5=map(voltage5,550,2250,0,180); 
int presentangle6=map(voltage6,550,2250,0,180); 
int error1=0.15*(desiredangle1-presentangle1); 
int error2=0.15*(desiredangle2-presentangle2); 
int error3=0.15*(desiredangle3-presentangle3); 
int error4=gripperangle1-presentangle4; 
int error5=gripperangle2-presentangle5; 
int error6=gripperangle3-presentangle6; 

if(error1>0) { 
analogWrite (EN1,150); 
digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH); 
delay(5); 
digitalWrite(IN1,HIGH); digitalWrite(IN2,HIGH); 
delay(5); } 
if(error1<0) {
analogWrite (EN1,150); 
digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW); 
delay(5); 
digitalWrite(IN1,HIGH); digitalWrite(IN2,HIGH);
delay(5);
}
if(error2>0)
{
analogWrite (EN2,150);
digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH);
delay(5);
digitalWrite(IN3,HIGH); digitalWrite(IN4,HIGH);
delay(5);
}
if(error2<0)
{
analogWrite (EN2,150);
digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
delay(5);
digitalWrite(IN3,HIGH); digitalWrite(IN4,HIGH);
delay(5);
}
if(error3>0)
{
analogWrite (EN3,150);
digitalWrite(IN5,LOW); digitalWrite(IN6,HIGH);
delay(2);
digitalWrite(IN5,HIGH); digitalWrite(IN6,HIGH);
delay(2);
}
if(error3<0)
{
analogWrite (EN3,150);
digitalWrite(IN5,HIGH); digitalWrite(IN6,LOW);
delay(2);
digitalWrite(IN5,HIGH); digitalWrite(IN6,HIGH);
delay(2);
}
myservo1.write(gripperangle1);
myservo2.write(gripperangle2);
myservo3.write(gripperangle3);
}
