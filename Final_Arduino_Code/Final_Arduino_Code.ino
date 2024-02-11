// Include libraries
#include<Servo.h>
#include "Arduino.h"
#define SPEAKER_PIN 11

// Initialize the servos
Servo s1; //Servo for the base, allowing for rotation
Servo s2; //Servo for the lowest element, the elbow servo
Servo s3; //Servo for the second element, the 'middle' servo

int joyX = 0; // Give variable to joystick readings
int joyY = 1;


int user_input_angle;
int i;

const int buttonPin = 2; //Pin number for GUN
const int ledPin = 3; //Pin number for the LED
int buttonState = 0; //Variabe for reading the button

int burst = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Sets the terminal frequency to 9600 hz (bits/sec)
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);


  s1.attach(5);  //Attaches servo to pin 5
  s2.attach(6);  //Attaches servo to pin 6
  s3.attach(7);  //Attaches servo to pin 7

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  pinMode(SPEAKER_PIN, OUTPUT);

  Serial.println("\nArduino is READY");
}

void loop() {
  // put your main code here, to run repeatedly:

  s1.write(map(analogRead(A1), 0, 1023, 0, 180));
  s2.write(map(analogRead(A0), 0, 1023, 0, 180));
  //Serial.println(analogRead(A2)); //Press Joystick down button. Use this for wrist rotation

  Serial.println(map(analogRead(A0), 0, 1023, 0, 180));

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); //Turn on the LED, Activate the gun
    Serial.println("FIRE FIRE FIRE");
    delay(1000);
    Serial.println("FIRE FIRE FIRE");
    delay(1000);
    Serial.println("FIRE FIRE FIRE");
    delay(1500);

    // Define the frequency of each note (in Hz)
    int melody[] = {
      130, 180, 220, 260, 310, 360, 400, 450, 500, 550, 600, 650, 700, 350, 200, 750, 800, 850, 900, 950, 1000, 850, 875, 1050, 1100, 1150, 1200, 200, 400, 200, 600, 742, 124, 1300, 1350, 1400, 1450, 1000, 500, 800, 987, 923, 123, 1600, 1650, 900, 800, 700, 900, 1850, 1900, 400, 2000, 2050, 2100, 2150, 500, 600, 230, 540
    };
  // Define the duration of each note (in milliseconds)
  int noteDuration = 100;
  // Play the melody
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
      tone(SPEAKER_PIN, melody[i], noteDuration);
      delay(noteDuration * 1.3); // Adjust delay for note duration
    }

    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("Safety On");
  }

  delay(50);

}
