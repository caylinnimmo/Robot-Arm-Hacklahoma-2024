// Include libraries
#include<Servo.h>
#include "Arduino.h"

// Initialize the servos
Servo s1; //Servo for the base, allowing for rotation
Servo s2; //Servo for the lowest element, the elbow servo
Servo s3; //Servo for the second element, the 'middle' servo
Servo s4; //Servo for hand rotation, this allows for an additional degree of freedom rotation
Servo s5; //Servo for the claw, allows for claw articulation
Servo s6; //Servo for the claw, allows for clamping of compenent. Drives geared claw elements

int user_input_angle;
int i;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //Sets the terminal frequency to 9600 hz (bits/sec)
Serial.println("\nArduino is READY");

s1.attach(5);  //Attaches servo to pin 5
s2.attach(6);  //Attaches servo to pin 6
s3.attach(7);  //Attaches servo to pin 7
s4.attach(8);  //Attaches servo to pin 8
s5.attach(9);  //Attaches servo to pin 9
s6.attach(10); //Attaches servo to pin 10



}

void loop() {
  // put your main code here, to run repeatedly:


  // s1.write(90);
  // Serial.println("Servo 1 90deg");
  // delay(2500);
  // s1.write(180);
  // Serial.println("servo 1 180 deg");
  // delay(2500);
  s2.write(130);
  Serial.println("Servo 2 90deg 5 sec");
  delay(2500);
  s2.write(160);
  Serial.println("Servo 2 150deg");
  delay(2500);
  // s3.write(0);
  // Serial.println("Servo 3 90deg");
  // s4.write(0);
  // Serial.println("Servo 4 90deg");
  // s5.write(0);
  // Serial.println("Servo 5 90deg");
  // s6.write(0);
  // Serial.println("Servo 6 90deg");

  delay(2500);

}
