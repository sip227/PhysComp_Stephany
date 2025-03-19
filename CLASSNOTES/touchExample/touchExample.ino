//Touch used a wired for the values no special tool

const int touchPin = 11;

const int ledPin = 4;

int touchThreshold = 50000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int touchVal = touchRead(touchPin);

    if (touchVal > touchThreshold)  //if touchVal goes above threshold...
  {
    digitalWrite(ledPin, 1);    //turn on LED
  }
  else
  {
    digitalWrite(ledPin, 0);    //turn off LED
  }

  int mapVal = map(touchVal, 31110, 170000, 0, 1000);

  Serial.printf("Touch Read = %i \t Touch Mapped = %i \n", touchVal, mapVal);

}
