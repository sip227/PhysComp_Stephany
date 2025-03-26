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

//HEIGHT
int ellipseH = 130;
int ellipseW = 200;

//Background color
int backr = 255;
int backg = 255;
int backb = 255;

//Lamp Color
int r, g, b = 0;

//Timing to slow flashing
int lastColorTime = 0;
int changeTimeInterval = 1000;


void setup()
{
  size(600,600);
  //1 is for home pc
  String portName = Serial.list()[1];
  
  myPort = new Serial(this, portName, 115200);
  background(backr, backg, backb);
  
}

void draw()
{
  //background(backr, backg, backb);
  if (myPort.available() > 0)
  {
    val = myPort.read();
    if(millis() - lastColorTime > changeTimeInterval)
  {
       if (val != 0 && val <=200)
  {
    r = int(random(0, 255));
    g = int(random(0, 255));
    b = int(random(0, 255));
  }
        else if( val > 200)
    {
      ellipseH = ellipseH + val;
    }
        else
  {
    r = 255;
    g = 222;
    b = 33;
  }
  
  lastColorTime = millis();
  }

  }  
  
  //Color for base of Lamp
  fill(227, 243, 242);
  ellipse(ellipseX, ellipseY, ellipseH , ellipseW);
  //Hat Lamp
  fill(r,g,b);
  quad(quad1x, quad1y, quad2x, quad2y, quad3x, quad3y, quad4x, quad4y);  
  
}
