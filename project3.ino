#include <Servo.h>

Servo myServo;  // Create a servo object

// Pin definitions
const int redPin = 2;
const int yellowPin = 3; // Single yellow LED
const int greenPin = 4;
const int servoPin = 9;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  // Attach the servo to the pin
  myServo.attach(servoPin);
  
  // Start with the motor open (0 degrees)
  myServo.write(0); // Assuming 0 degrees is open
}

void loop() {
  // Green light
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  myServo.write(0); // Open the motor (up) to allow cars to pass
  delay(5000); // Green light duration (5 seconds)

  // Yellow light (after green)
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000); // Yellow light duration (2 seconds)
  myServo.write(90); // Close the motor (down) to stop cars
  delay(2000); // Yellow light duration (2 seconds)

  // Red light
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  myServo.write(90); // Keep the motor closed (down) to stop cars
  delay(5000); // Red light duration (5 seconds)

  // Yellow light (after red)
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000); // Yellow light duration (2 seconds)
  myServo.write(0); // Open the motor (up) to allow cars to prepare to pass
  delay(2000); // Yellow light duration (2 seconds)

  // Repeat the cycle
}
