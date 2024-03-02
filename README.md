# Servo Motor with Pushbutton Task

Welcome to the Servo Motor with Pushbutton task! This task demonstrates how to control a servo motor using a pushbutton and an Arduino. By pressing the pushbutton, you can rotate the servo motor to a predefined angle. This task combines the principles of servo motor control and digital input with Arduino.

## Introduction

The Servo Motor with Pushbutton task aims to provide a practical example of integrating a pushbutton with a servo motor for control. Servo motors are commonly used in robotics and automation for precise angular positioning, while pushbuttons are simple digital input devices that can trigger actions in microcontroller-based systems.

## How it Works

The task works by using the pushbutton as an input to trigger the rotation of the servo motor. When the pushbutton is pressed, the Arduino reads the button state and sends a corresponding control signal to the servo motor to rotate it to a predefined angle. This allows users to control the servo motor's position with a simple press of a button.

## Getting Started

To get started with this task, you will need the following components:

- Arduino board (e.g., Arduino Uno)
- Servo motor
- Pushbutton
- Jumper wires
- Breadboard

## Steps

Follow these steps to set up the task:

1. Connect the signal wire of the servo motor to one of the PWM pins on the Arduino (e.g., pin 9).
2. Connect the power (VCC) wire of the servo motor to the 5V pin on the Arduino.
3. Connect the ground (GND) wire of the servo motor to the GND pin on the Arduino.
4. Connect one leg of the pushbutton to a digital pin on the Arduino (e.g., pin 2).
5. Connect the other leg of the pushbutton to the ground (GND) pin on the Arduino.
6. Ensure all connections are secure.

| Arduino Pin    | Component      |
| -------------- | -------------- |
| PWM ( 9)       | Servo Motor    |
| 5V             | Servo Motor    |
| GND            | Servo Motor    |
| Digital ( 2)   | Pushbutton     |
| GND            | Pushbutton     |

## Connection

The following table summarizes the wiring connections between the Arduino, servo motor, and pushbutton:

![screen-gif](https://github.com/ItsRawanMoha/Servo-Motor-with-Pushbutton/blob/main/ServoMotorwithPushbutton.png)

## Output

Once the circuit is set up and the code is uploaded to the Arduino board, pressing the pushbutton should trigger the rotation of the servo motor to the predefined angle.

## Code
```
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
```
## Pictures

<img src="https://github.com/ItsRawanMoha/Servo-Motor-with-Pushbutton/blob/main/ServoMotorwithPushbuttonP.jpeg" alt="Alt text" width="300" height="400">  ![screen-gif](https://github.com/ItsRawanMoha/Servo-Motor-with-Pushbutton/blob/main/ServoMotorwithPushbuttonG.gif)

## Conclusion

The Servo Motor with Pushbutton task provides a practical demonstration of integrating pushbutton input with servo motor control using Arduino. By understanding the principles behind this task, you can explore more complex applications and tasks involving servo motors and digital input devices.
