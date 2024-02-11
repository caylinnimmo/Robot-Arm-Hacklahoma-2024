// Arduino Joystick Module Testing Code
// Reference Video: https://www.youtube.com/watch?v=F39-1hnjWn0

#include <Servo.h> // Include servo library

Servo servo1; // Define servos
Servo servo2;

int joyX = 0; // Give variable to joystick readings
int joyY = 1;

int joyVal; // Create variable for joystick value

void setup() {
  servo1.attach(3); // Initiate servos
  servo2.attach(4);
}

void loop() {
  joyVal = analogRead(joyX); // Read value from joystick
  joyVal = map(joyVal, 0, 1023, 0, 180); // Change value range to 0-180
  servo1.write(joyVal); // Write value to servo

  joyVal = analogRead(joyY); // Repeat same for y-axis
  joyVal = map(joyVal, 0, 1023, 0, 180);
  servo2.write(joyVal);
  delay(20); // Add small delay to reduce noise
}
