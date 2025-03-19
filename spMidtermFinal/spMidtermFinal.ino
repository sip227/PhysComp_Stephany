/*
MIDTERM - Lights y Piezo

*problem with connecting straight to pin
also conflict with delay and millis and pot
header files work 
*

*/

//Libraries
#include "pitches.h"

//MElODIES
#include "twinkleS.h"

//Button Pin
const int buttonPin = 9;
//Pot Pin
const int potPin = 1;

//Piezo

const int piezoPin = 21;

//LED PINS
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 15;
const int ledPin5 = 16;
const int ledPin6 = 17;

//timer
unsigned long currentMillis1 = 0;
unsigned long previousMillis1 = 0;

unsigned long currentMillis2 = 0;
unsigned long previousMillis2 = 0;

int timerInterval1 = 1000;

int timerInterval2 = 2000;

// Potentiometer Value
int potValue = 0;

// Button States
bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;

void setup() {
  analogReadResolution(10);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Read potentiometer
  potValue = analogRead(potPin);
  timerInterval1 = map(potValue, 0, 1023, 10, 1000);
  timerInterval2 = map(potValue, 0, 1023, 10, 1000);

  int size = sizeof(twinkleDuration) / sizeof(int);

  for (int note = 0; note < size; note++)
    {
      int duration = 1000 / twinkleDuration[note];
      tone(piezoPin, twinkle[note], duration);
      int pauseBetweenNotes = duration * 1.30;
      delay(pauseBetweenNotes); 

        }

  // Read button state
  buttonState = !digitalRead(buttonPin);

  // Handle button press for turning LEDs on/off
  if (buttonState && !lastButtonState) {
    toggle = !toggle;
  }

  if (!buttonState && lastButtonState) {
    fallToggle = !fallToggle;
  }

  // Update button state for next loop
  lastButtonState = buttonState;

  // If offState is true, turn off all LEDs
  if (toggle) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
  } 
  else {

    // Toggle the LEDs based on potentiometer range and button toggle
      if (0 <= potValue && potValue <= 399) {
        currentMillis1 = millis();
        if (currentMillis1 - previousMillis1 >= timerInterval1) {
          previousMillis1 = currentMillis1;
          digitalWrite(ledPin1, !digitalRead(ledPin1));
          digitalWrite(ledPin2, !digitalRead(ledPin2));
          digitalWrite(ledPin3, !digitalRead(ledPin3));
        }
  
      } 
      else if (400 <= potValue && potValue <= 1023) {
        currentMillis2 = millis();
        if (currentMillis2 - previousMillis2 >= timerInterval2) {
          previousMillis2 = currentMillis2;
          digitalWrite(ledPin4, !digitalRead(ledPin4));
          digitalWrite(ledPin5, !digitalRead(ledPin5));
          digitalWrite(ledPin6, !digitalRead(ledPin6));
        }


      }
    }
  }


  


