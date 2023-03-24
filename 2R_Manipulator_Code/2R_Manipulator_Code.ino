#include <Servo.h>
Servo myservo1,myservo2;
void setup() {
  Serial.begin(9600);
  myservo1.attach(2);
  myservo2.attach(4);
}

void loop() {
  if (Serial.available() > 0)
  {
    String theta1degree = Serial.readStringUntil(',');
    Serial.read();
    String theta2degree = Serial.readStringUntil('\0');
    int theta1 = theta1degree.toInt();
    int theta2 = theta2degree.toInt();
    Serial.print("theta1 is ");
    Serial.println(theta1);
    Serial.print("theta2 is ");
    Serial.println(theta2);
    myservo1.write(theta1);
    myservo2.write(theta2);
  }

}
