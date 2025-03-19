//CLASS NOTES
IN CLASS EXAMPLE
const int ledPin =4;

const int piezoPin = 21;

const int touchPin = 10;

int ms = 30;

void setup() {
  // put your setup code here, to run once:
  analogWriteResolution(piezoPin, 16);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //tone(piezoPin, 220, 500);
  //tone(piezoPin, 440, 1000);
  // tone(piezoPin, 110, 200);
  // tone(piezoPin, 200, 1000);
  // tone(piezoPin, 200, 200);
  // tone(piezoPin, 100, 200);

//PLUG IN A TOUCH POINT TO touchPin, & UNCOMMENT BELOW FOR SOMETHING WILDER!
   int touchVal = touchRead(touchPin); //read capacitive touch value
   int mapVal = map(touchVal, 27000, 200000, 300, 1000);
   Serial.printf("TOUCH = %i \t MAP = %i \n", touchVal, mapVal);
   analogWriteFrequency(piezoPin, mapVal);    //set PWM frequency
   analogWrite(piezoPin, 127);                //write PWM @ set frequency

}
