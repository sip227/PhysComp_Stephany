//WIP - STEPHANY PENA
//VISUALIZING THE INTENDED EVENTS NATIVELY VIA PROCESSING


import gifAnimation.*; //HELPS TO PLAY GIF ANIMATION VIA LIBRARY
//SET UP COMMUNICATION
//import processing.serial.*;

//Serial myPort;


//IMAGES
PImage normalAzu;
PImage bnormalAzu;
PImage madAzu;
PImage happyAzu;

//GIFs
Gif bonk;
Gif headpat;

//LOCATION
int pngX = 115;
int pngY = 250;



void setup()
{
  size(600,600);
  //LOAD
  normalAzu = loadImage("images/normalAzu1.png");
  bnormalAzu = loadImage("images/normalAzu2.png");
  madAzu = loadImage("images/madAzu.png");
  happyAzu = loadImage("images/happyAzu.png");
  
  bonk = new Gif(this, "images/bonk.gif");
  bonk.loop();
  
  headpat = new Gif(this, "images/headpat.gif");
  headpat.loop();
  //RESIZE 
  normalAzu.resize(0,350);
  bnormalAzu.resize(0,350);
  madAzu.resize(0,350);
  happyAzu.resize(0,350);
  
  //frameRate(30);
}

void draw()
{
  background(255);
  
  image(normalAzu, pngX, pngY);

  if(mousePressed)
  {
    background(255);
    //image(bonk, pngX, pngY);
    image(madAzu, pngX, pngY);
    image(bonk, 240, 125, 200, 200);
  }
  if(keyPressed)
  {//This one will be fine to recieve data and play as is
    background(255);
    image(happyAzu, pngX, pngY);
    image(headpat, 205, 185, 200, 200);
  }
}
