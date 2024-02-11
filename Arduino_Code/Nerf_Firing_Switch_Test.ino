// Hacklahoma Electronic Nerf Firing Switch Test

const int firePin = 6; // Pin number for the firing switch

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(firePin, OUTPUT); // Set the firePin as an output
  Serial.println("Ready to Start!");
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming byte from the serial port
    char receivedByte = Serial.read();

    // Check if the received byte is '1' or '0'
    if (receivedByte == '1') {
      digitalWrite(firePin, HIGH); // Begin firing
      Serial.println("FIRE, FIRE, FIRE!");
      delay(3000);
      digitalWrite(firePin, LOW);
    } else if (receivedByte == '0') {
      digitalWrite(firePin, LOW); // Stop firing
      Serial.print("Saftey on");
    }
  }
}
