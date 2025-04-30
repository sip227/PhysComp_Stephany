// WIP - STEPHANY PENA

// IMAGES
PImage normalAzu;
PImage bnormalAzu;
PImage madAzu;

// BLINK ARRAY
PImage[] blink = new PImage[2];  // [0] open, [1] closed

// LOCATION
int pngX = 115;
int pngY = 250;

// BLINK CONTROL
boolean isBlinking = false;
int blinkStart = 0;
int blinkDuration = 6;
int nextBlinkDelay = 0;

void setup() {
  size(600, 600);

  // LOAD
  normalAzu = loadImage("images/normalAzu1.png");
  bnormalAzu = loadImage("images/normalAzu2.png");
  madAzu = loadImage("images/madAzu.png");

  // RESIZE
  normalAzu.resize(0, 350);
  bnormalAzu.resize(0, 350);
  madAzu.resize(0, 350);

  // BLINK ARRAY
  blink[0] = normalAzu;
  blink[1] = bnormalAzu;

  // Schedule first blink
  scheduleNextBlink();
}

void draw() {
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
    if(mousePressed)
  {
    background(255);
    image(madAzu, pngX, pngY);
  }
}

void scheduleNextBlink() {
  blinkStart = frameCount;
  nextBlinkDelay = int(random(120, 300)); // 2 to 5 seconds
}
