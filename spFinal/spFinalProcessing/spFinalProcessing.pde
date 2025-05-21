//WIP - STEPHANY PENA
//VISUALIZING THE INTENDED EVENTS NATIVELY VIA PROCESSING


import gifAnimation.*; //HELPS TO PLAY GIF ANIMATION VIA LIBRARY
//SET UP COMMUNICATION
import processing.serial.*;

Serial myPort;

byte [] val = {0,0,0};


//IMAGES
PImage normalAzu;
PImage bnormalAzu;
PImage madAzu;
PImage happyAzu;

//Array
PImage[] blink = new PImage[2];

// BLINK CONTROL
boolean isBlinking = false;
int blinkStart = 0;
int blinkDuration = 6;
int nextBlinkDelay = 0;

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
  //bonk.play();
  bonk.ignoreRepeat();
  //bonk.noLoop();
  
  headpat = new Gif(this, "images/headpat.gif");
  headpat.loop();
  //RESIZE 
  normalAzu.resize(0,350);
  bnormalAzu.resize(0,350);
  madAzu.resize(0,350);
  happyAzu.resize(0,350);
  
  
  // BLINK ARRAY
  blink[0] = normalAzu;
  blink[1] = bnormalAzu;

  // Schedule first blink
  scheduleNextBlink();

  
  //frameRate(30);
  printArray(Serial.list());
  String portName = Serial.list()[0]; 
  myPort = new Serial(this, portName, 115200);  
}

void draw()
{
  if (myPort.available() > 0)
  {
    val = myPort.readBytesUntil('e'); 
  }
  background(255);
  
   // Time since last blink started
  int timeSinceBlink = frameCount - blinkStart;

  if (isBlinking) {
    // During blink
    if (timeSinceBlink < blinkDuration) {
      image(blink[1], pngX, pngY); // Eyes closed
    } else {
      isBlinking = false;
      scheduleNextBlink(); // Schedule the next blink after this one
      image(blink[0], pngX, pngY); // Eyes open
    }
  } else {
    if (timeSinceBlink >= nextBlinkDelay) {
      // Start blinking
      isBlinking = true;
      blinkStart = frameCount;
      image(blink[1], pngX, pngY); // Eyes closed
    } else {
      image(blink[0], pngX, pngY); // Eyes open
    }
  }

  
  if (val.length == 3) //Might be why it changes between states
  {
    int pirSensor = int(map(val[1], -128, 127, 0, 255));
    int forceSensor = int(map(val[2], -128, 127, 0, 255));
      if(forceSensor > 950)
      {//will need to fix this as i want bonk to play at time of bonking
        background(255);
    //image(bonk, pngX, pngY);
        image(madAzu, pngX, pngY);
        bonk.play();
        image(bonk, 240, 125, 200, 200);
      }
      if(pirSensor > 100) //10 makes its in the headpat state, 150 is when it signals
      {
        background(255);
        image(happyAzu, pngX, pngY);
        image(headpat, 205, 185, 200, 200);
      }
  }

}

void scheduleNextBlink() {
  blinkStart = frameCount;
  nextBlinkDelay = int(random(120, 300)); // 2 to 5 seconds
}
