#include <Servo.h>//program by Nepro.

// Pin assignments for IR sensors
const int irSensor1 = 2;  // Connect the first IR sensor to pin 2
const int irSensor2 = 3;  // Connect the second IR sensor to pin 3

// Pin assignment for servo
const int servoPin = 9;   // Connect the servo control wire to pin 9

Servo myServo;

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);

  myServo.attach(servoPin);
}

void loop() {
  // Check the status of IR sensors
  int ir1Value = digitalRead(irSensor1);
  int ir2Value = digitalRead(irSensor2);

  if (ir1Value == LOW) {
    // Train detected by the first IR sensor, close the servo
    closeServo();
  } else if (ir2Value == LOW) {
    // Train detected by the second IR sensor, or change in color
    openServo();
  }
}

void closeServo() {
  // Close the servo up to 90 degrees
  myServo.write(90);
  delay(1000);  // Adjust the delay as needed
}

void openServo() {
  // Open the servo
  myServo.write(0);  // Adjust the angle as needed
  delay(1000);  // Adjust the delay as needed
}
