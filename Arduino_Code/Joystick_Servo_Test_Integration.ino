// Arduino Joystick Module Testing Code
// Reference Video: https://www.youtube.com/watch?v=F39-1hnjWn0

#include <Servo.h> // Include servo library

Servo servo1; // Define servos
Servo servo2;

int joyX = 0; // Give variable to joystick readings
int joyY = 1;

int joyValX; // Create variable for joystick value
int joyValY;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  // servo1.attach(3); // Initiate servos
  // servo2.attach(4);
  //Serial.println("setup");
}

void loop() {
  // joyValX = analogRead(joyX); // Read value from joystick
  // joyValX = map(joyValX, 0, 1023, 0, 180); // Change value range to 0-180
  //Serial.println(map(analogRead(A0), 0, 1023, 0, 180));
  // servo1.write(joyVal); // Write value to servo

  //joyValY = analogRead(joyY); // Repeat same for y-axis
  Serial.println(map(analogRead(A1), 0, 1023, 0, 180));
  //Serial.println(joyValY);
  //Serial.println("print statement");

  delay(300);
  // joyVal = map(joyVal, 0, 1023, 0, 180);
  // servo2.write(joyVal);
  // delay(20); // Add small delay to reduce noise
}
