//BUTTON SET UP
//SIMPLE PUSH BUTTON

const int  buttonPin = 9;

void setup() {
  // put your setup code here, to run once:
  //pinMode(buttonPin, INPUT_PULLDOWN); //USE FOR 3.3V //wIRING IS CONSISTENT
  pinMode(buttonPin, INPUT_PULLUP); //USE GROUND
  Serial.begin(115200);



}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = !digitalRead(buttonPin); //use ! when using pullup
  Serial.println(buttonState);

}
