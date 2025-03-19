//POT

//POT PROBLEM ONE
/*
1. ADC Pot read is too jumpy

2. Pot doesn't respond full term




*/
const int potPin =1;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int adcVal = analogRead(potPin);
  Serial.println(adcVal);
  delay(200);

}
