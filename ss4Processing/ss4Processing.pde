//SS4

import processing.serial.*;

Serial myPort;

byte[] val = {};

//LAMP
int quad1x = 217;
int quad1y = 160;

int quad2x = 177;
int quad2y = 292;

int quad3x = 390;
int quad3y = 292;

int quad4x = 340;
int quad4y = 160;

//Base Of Lamp
int ellipseX = 280;
int ellipseY = 315;

//HEIGHT
int ellipseH = 130;
int ellipseW = 200;

//Background color
int backr = 255;
int backg = 255;
int backb = 255;

//Lamp Color
int r, g, b = 0;


void setup()
{
  size(600,600);
  
  printArray(Serial.list());
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 115200);
  background(backr, backg, backb);
  
}

void draw()
{
  if (myPort.available() > 0)
{
  val = myPort.readBytesUntil('e');
}
 if (val.length == 5)
 {
   int pot_1 = int(map(val[2], -128, 127, 0, 255));
   int pot_2 = int(map(val[3], -128, 127, 0, 255));
   
   boolean b_1 = boolean(val[0]);
   boolean b_2 = boolean(val[1]);
   
  fill(227, 243, 242);
  ellipse(ellipseX, ellipseY, ellipseH , ellipseW);
  //Hat Lamp
  fill(r,g,b);
  quad(quad1x, quad1y, quad2x, quad2y, quad3x, quad3y, quad4x, quad4y);
  
  if(pot_1 > 20)
  {
    ellipseX = ellipseX - 10;
  }
  
  if (b_1)
  {
    //RED
    r = int(random(200, 255));
    g = int(random(0, 55));
    b = int(random(0, 95));
  }
  else
  {//YELLOW
    r = 255;
    g = 222;
    b = 33;
  }
  
  if (b_2)
  {
    r = int(random(0, 105));
    g = int(random(200, 255));
    b = int(random(0, 105));
  }
  else
  {
    //YELLOW
    r = 255;
    g = 222;
    b = 33;
  }
     
 }
 


}
