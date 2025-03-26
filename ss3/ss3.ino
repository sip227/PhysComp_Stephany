//SS3
//VARIABLES
const int adcPin = 1;
int adcRead = 0;

int lastTime = 0;

int currentTime = 0;

int timerInterval = 20;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  if ()
  {
    lastTime = currentTime;
    adcRead = analogRead(adcPin);

    Serial.write(adcRead);
  }

}
