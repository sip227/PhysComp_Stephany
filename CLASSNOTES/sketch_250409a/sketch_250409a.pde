import processing.serial.*;

Serial myPort;

void setup()
{
  size(500,500);
  background(255);
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
  //DRAW RECTANGLE AREAS
  fill(200);
  rect(0, width/2, width, height/2);
  fill(255, 255, 0);
  rect(0, 0, width/2, height/2);
  fill(0, 255, 0);
  rect(width/2, 0, width/2, height/2);
  
  //TEXT
  fill(0);
  text("this light", width/4, height/4);
  text("that light", width-width/4, height/4);
  text("no light", width/4, height-height/4);
  
  //MOUSE
  if (mouseY > width/2 && mouseY < height)
  {
    myPort.write(0); // SEND 0
  }
  else if (mouseX < width/2 && mouseX > 0)
  {//LEFTSIDE OF SCREEN
    myPort.write(1);
  }
  else if (mouseX > width/2 && mouseX < width)
  {
    myPort.write(2);
  }
  else
  {
    myPort.write(2);
  }
  
  
}
