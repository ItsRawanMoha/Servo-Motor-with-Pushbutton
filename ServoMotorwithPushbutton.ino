#include <Servo.h>

// Define constants
const int buttonPin = 2;  // Push button pin
const int servoPin = 9;   // Servo motor control pin

// Create a Servo object
Servo myServo;

// Variables
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  // Attach servo to its pin
  myServo.attach(servoPin);

  // Set button pin as input
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Toggle the servo position
    if (myServo.read() == 0) {
      myServo.write(180);  // Move the servo to 180 degrees
    } else {
      myServo.write(0);    // Move the servo to 0 degrees
    }
  }

  // Save the current button state for the next iteration
  lastButtonState = buttonState;
}
