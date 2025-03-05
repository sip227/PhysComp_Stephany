//SS2 - Stephany Pena

//VARIABLES
int counter = 0;
int ms = 300;
//Button
const int buttonPin = 9;
bool buttonState = 0; //current button state
bool lastButtonState = 0; //previous button state
//bool toggle = 0; //toggle for rising edge
//bool fallingToggle = 0; // toggle for falling edge


//LEDS
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);


  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);


  //DEBUG
  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = !digitalRead(buttonPin);
  if(buttonState)//if buttone went from LOW to HIGH
  { 
    //toggle = !toggle;
    counter++;
    
  }

  //FALLING EDGE
 /* if(!buttonState && lastButtonState)//if buttone went from HIGH to LOW
  {
    fallingToggle = !fallingToggle;
  }*/
  
  if(counter==1)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, LOW); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, HIGH);
    delay(ms); 
  }
  else if(counter==2)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, HIGH);
    delay(ms); 

  }
  else if(counter==3)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, HIGH); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, LOW);
    delay(ms); 
  }
  else if(counter==4)
  {
    digitalWrite(ledPin1, HIGH);
    delay(ms);
    digitalWrite(ledPin2, HIGH);
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms); 
    digitalWrite(ledPin4, HIGH); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    delay(ms);
    digitalWrite(ledPin2, LOW);
    delay(ms);
    digitalWrite(ledPin3, LOW); 
    delay(ms);
    digitalWrite(ledPin4, LOW);
    delay(ms); 
  }
  else{
    delay(ms); 
    counter = 0;
  }
  lastButtonState = buttonState;
  Serial.printf("Button =%i,Counter = %i \n", buttonState, counter);
  
}