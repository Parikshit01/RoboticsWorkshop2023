#include <Servo.h>

Servo myservo1, myservo2, myservo3, myservo4, myservo5;
int pos = 0;
void setup() {
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(7);
  myservo4.attach(8);
  myservo5.attach(9);
}

void loop() {
  for (pos = 0; pos <= 120; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    delay(60);
  }
  for (pos = 120; pos >= 0; pos -= 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    delay(60);
  }
}


