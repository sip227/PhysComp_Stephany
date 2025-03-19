//IN CLASS EXAMPLE
//Also used photocell
const int potPin =1;

const int numReads = 16;

int reading[numReads];

int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(11);

}

void loop() {
  // put your main code here, to run repeatedly:
  reading[count] = analogRead(potPin);
  count++;

  if (count >= numReads)
  {
    count = 0;
  }
  int sum = 0;

  for(int i = 0; i < numReads; i++)
  {
    sum += reading[i];
  }

  int analogValue = sum / numReads;

  //Serial.println(analogValue);

  int mapVal = map(analogValue, 0, 1619, 0, 255);

  rgbLedWrite(38, mapVal, mapVal, 0);

  Serial.printf("ADC raw = %i \t ADC averaged = %i \t ADC mapped = %i \n", analogRead(potPin), analogValue, mapVal);


}
