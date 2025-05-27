#include <Arduino.h>
#include <Servo.h>

Servo myServo;
Servo myServo2;
const int servoPin = 9;
const int servoPin2 = 10;

void setup() {
  myServo.attach(servoPin);
  myServo2.attach(servoPin2);
  myServo.write(25);  
  myServo2.write(25);
  Serial.begin(9600);  
  Serial.setTimeout(10); 
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  

    if (input == "correct") {
      myServo.write(50);
      myServo2.write(0);
      delay(2000);
      myServo.write(25);
      myServo2.write(25);
    } else if (input == "wrong") {

      Serial.println("Received 'wrong', no action taken.");
    } else {
      Serial.println("Unknown command.");
    }
  }
}
