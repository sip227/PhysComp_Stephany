//MARCH 5th CLASS
//ESP32 BOARD LED
const int pinRGB =38;

//VARIABLES
int brightness = 4;

int delayTime = 1000;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  rgbLedWrite(pinRGB, brightness, brightness, brightness); //WHITE
  delay(delayTime);
  rgbLedWrite(pinRGB, brightness, 0, 0); //RED
  delay(delayTime);
  rgbLedWrite(pinRGB, 0, brightness, 0); //GREEN
  delay(delayTime);
  rgbLedWrite(pinRGB, 0, 0, brightness); //BLUE
  delay(delayTime);
  rgbLedWrite(pinRGB, brightness, brightness, 0);
  delay(delayTime);
  rgbLedWrite(pinRGB, brightness, 0, brightness);
  delay(delayTime);
  rgbLedWrite(pinRGB, 0, brightness, brightness);
  delay(delayTime);
}
