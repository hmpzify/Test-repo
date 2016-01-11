#include <Servo.h>
#include <.h>


Servo myservo;


void setup() {
  myservo.attach(9);
 // myservo.write(90);

}

void loop() {
    delay(10000);
    myservo.write(45);
    delay(10000);
    myservo.write(135);
    delay(10000);

  
}
