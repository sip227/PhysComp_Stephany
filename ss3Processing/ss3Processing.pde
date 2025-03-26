//SS3
import processing.serial.*;

Serial myPort;
int val = 0;

void setup()
{
  size(600,600);
  
  String portName = Serial.list()[0];
  
  myPort = new Serial(this, portName, 115200);
  
  
}

void draw()
{
  
  if (myPort.available() > 0)
  {
    val = myPort.read();
  }
}
