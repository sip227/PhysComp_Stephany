import processing.serial.*;

Serial myPort;

String incomingData;
int val = 0;
void setup()
{
  size(600,600);
  //background(255);
  fill(0);
  textSize(22);
  textAlign(CENTER, CENTER);
  noStroke();
  
  //SERIAL COMMUNICATION
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
}

void draw()
{
  background(255);
 if(myPort.available()> 0)
 {
  incomingData = myPort.readStringUntil('\n'); 
  if(incomingData != null)
  {
    val = int(trim(incomingData));
  }
 }
 
 if(val > 500)
 {
   text("OUCH", width/2, height/2);
 }
 else
 {
   text("Not Ouch", width/2, height/2);
 }
 
 //background(255);
}
