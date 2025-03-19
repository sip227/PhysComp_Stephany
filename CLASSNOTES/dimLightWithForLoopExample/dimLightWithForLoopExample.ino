//CLass Notes
//with the for loop

const int ledPin = 4;
int ms = 10;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++)  //starting from 0, incrementing to 255
  {
    analogWrite(ledPin, i); //send PWM signal @ current i value
    delay(ms);
    Serial.printf("FOR LOOP 1: %i \n",i);
  }

    for (int i = 255; i > 0; i--) //starting from 255, decrementing to 0
  {
    analogWrite(ledPin, i); //send PWM signal @ current i value
    delay(ms);
    Serial.printf("FOR LOOP 2: %i \n",i);
  }


}
