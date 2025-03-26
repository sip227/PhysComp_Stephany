//SS3
import processing.serial.*;

Serial myPort;
int val = 0;

//lamp vals
//Lamp
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

//Background color
int backr = 255;
int backg = 255;
int backb = 255;

//Lamp Color
int r, g, b = 0;

void setup()
{
  size(600,600);
  
  String portName = Serial.list()[0];
  
  myPort = new Serial(this, portName, 115200);
  background(backr, backg, backb);
  
}

void draw()
{
  
  if (myPort.available() > 0)
  {
    val = myPort.read();
    if (val != 0 && val <=255)
  {
    r = r++;
    g = g++;
    b = b++;
  }
    else
  {
    r = 255;
    g = 222;
    b = 33;
  }
  
  }
  //Color for base of Lamp
  fill(227, 243, 242);
  ellipse(ellipseX, ellipseY, 130, 200 );
  //Hat Lamp
  fill(r,g,b);
  quad(quad1x, quad1y, quad2x, quad2y, quad3x, quad3y, quad4x, quad4y);  
  
}
