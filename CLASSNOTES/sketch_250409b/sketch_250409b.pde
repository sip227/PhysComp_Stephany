int val = 0;

import processing.serial.*;  //import Serial library

Serial myPort;  // create object from Serial class

void setup() 
{
  size(600, 300); 
  background (255);
  fill(0);
  textSize (30);
  textAlign (CENTER);

  //set up Serial communication
  printArray(Serial.list()); // prints port list to the console
  String portName = Serial.list()[0]; //change to match your port
  myPort = new Serial(this, portName, 115200); //initialize Serial communication at 115200 baud
}
void draw()
{
  for(int i = 0; i < width; i++)
  {
    int c = int(map(i, 0, width, 0, 255));
    stroke(c * 2, c, 0);
    line(i, 0, i, height);
  }
  //TEXT
  fill(255);
  text("DIMMER", width/4, height/2);
  fill(0);
  text ("BRIGHTER", width-width/4, height/2);
  
  fill(0, 0, 255);
  circle(mouseX, mouseY, 20);
  //____GFX_END____//

  //mouse location controls communication to Serial 
  val = int (map (mouseX, 0, width, 0, 255)); //remaps mouseX to 0-255 range
  myPort.write(val);
  
}
