//Assignment One
int count = 0;

int ms = 200;

//LED PINS
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  
  if (count < 10){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, LOW); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, HIGH);
    delay(ms); 
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW);
    delay(500);
  }
  else if (count >= 10 && count < 20){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, HIGH);
    delay(ms); 
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW);
    delay(500);
  }
  else if (count >= 20 && count < 30) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, HIGH); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH); 
    digitalWrite(ledPin4, LOW);
    delay(ms); 
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW);
    delay(500);
  }
  else if (count >= 30 && count < 40){
    digitalWrite(ledPin1, HIGH);
    delay(ms);
    digitalWrite(ledPin2, HIGH);
    delay(ms);
    digitalWrite(ledPin3, HIGH);
    delay(ms); 
    digitalWrite(ledPin4, HIGH); 
    delay(ms);
    digitalWrite(ledPin1, LOW);
    delay(ms);
    digitalWrite(ledPin2, LOW);
    delay(ms);
    digitalWrite(ledPin3, LOW); 
    delay(ms);
    digitalWrite(ledPin4, LOW);
    delay(ms); 
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW);
    delay(500);
  }
  else{
    count = 0;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW);
  }
  //count++;
}
