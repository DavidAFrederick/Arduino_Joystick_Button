//https://forum.arduino.cc/t/joystick-library-multiple-button-presses/1083677/5
// https://forum.arduino.cc/t/joystick_-does-not-name-a-type-did-you-mean-joystick/658008
// >> https://github.com/MHeironimus/ArduinoJoystickLibrary


#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick;

// Constant that maps the physical pin to the joystick button.
const int pinToButton = 8;
const int LightPin = 9;
bool LED1 = false;

void setup() {
  // Initialize Button Pins
  pinMode(pinToButton, INPUT_PULLUP);
  pinMode(LightPin, OUTPUT);
  Serial.begin(9600);

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the button
int lastButtonState = 0;

void loop() {

  // Read pin values
  int currentButtonState = !digitalRead(pinToButton);

  if (currentButtonState != lastButtonState) {
    Joystick.setButton(0, currentButtonState);
    lastButtonState = currentButtonState;
    // Serial.print(currentButtonState);
    if (currentButtonState == 1) {
      LED1 = !LED1;
    }
  }

  digitalWrite(LightPin, LED1);  // true = LED On

  delay(10);
}
