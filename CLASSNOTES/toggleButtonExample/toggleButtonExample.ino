//Toggle BUTTON IN CLASS Example - EDGE DETECTION
//MARCH 5th


const int buttonPin = 9;
const int ledPin = 4;

bool buttonState = 0; //current button state
bool lastButtonState = 0; //previous button state
bool toggle = 0; //toggle for rising edge
bool fallingToggle = 0; // toggle for falling edge



void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = !digitalRead(buttonPin);

  //RISING EDGE DETECTION
  //Detects the Press of a button

  if(buttonState && !lastButtonState)//if buttone went from LOW to HIGH
  { 
    toggle = !toggle;
    
  }

  //FALLING EDGE
  if(!buttonState && lastButtonState)//if buttone went from HIGH to LOW
  {
    fallingToggle = !fallingToggle;
  }

  lastButtonState = buttonState;
  digitalWrite(ledPin, toggle);
  Serial.printf("Button =%i, Toggle =%i, Falling = %i \n", buttonState, toggle, fallingToggle);

}
