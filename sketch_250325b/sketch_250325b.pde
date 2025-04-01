

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

void setup()
{
  size(600,600);
  background(255);
}

void draw()
{
  ellipse(ellipseX, ellipseY, 130, 200 );
  quad(quad1x, quad1y, quad2x, quad2y, quad3x, quad3y, quad4x, quad4y);
  //ellipse(ellipseX, ellipseY, 75, 100 );
  println("X:", mouseX, "Y:", mouseY);

}
