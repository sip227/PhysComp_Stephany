//Stephany Pena Final

//Define Pins
const int pirSensorPin = 21;
const int forceSensorPin = 20;

//Pot Variables
int pirSensorRead = 0;
int forceSensorRead = 0;

//Software Timer Variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 20; //not reliable with values less than 20ms

void setup() 
{
  analogReadResolution(8);  
  Serial.begin(115200); //start serial comm @ 115200 baud rate
}

void loop() 
{

  pirSensorRead  = map(analogRead(pirSensorPin), 0, 255, -128, 127);
  forceSensorRead = map(analogRead(forceSensorPin), 0, 255, -128, 127);


  currentTime = millis(); //read current elapsed time
  if (currentTime - lastTime >= timerInterval)  
  {
    lastTime = currentTime; //store current time as lastTime so we know when timer last triggered

    //Send Data to Processing via Serial UART
    Serial.write(pirSensorRead);      //send 1st byte
    Serial.write(forceSensorRead);      //send 2nd byte
    Serial.write('e');            //send 'e' ASCII character to signal end of message
  }
}
