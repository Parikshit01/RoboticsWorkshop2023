#include <Servo.h>
Servo myservo1, myservo2, myservo3;

void setup() {
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(7);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0)
  {
    String angle1 = Serial.readStringUntil(',');
    Serial.read();
    String angle2 = Serial.readStringUntil(',');
    Serial.read();
    String angle3 = Serial.readStringUntil('\0');
    int angle1int = angle1.toInt();
    int angle2int = angle2.toInt();
    int angle3int = angle3.toInt();
    Serial.println(angle1int);
    Serial.println(angle2int);
    Serial.println(angle3int);
    myservo1.write(angle1int);
    myservo2.write(angle2int);
    myservo3.write(angle3int);
  }
}
