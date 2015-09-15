#include <Servo.h> 
/*
 * Based at Sweep example
 * 
 * This 'app' use servo for open trashcan,
 * sensor of opened door is reed switch (as button)
 * 
 * In closed state servo detached - for minimum noise and power save
 */
 
Servo myservo;  
int closed = 0;
int opened = 140;
int state = 0;
const int buttonPin = 2;
const int ledPin =  13; 
const int servoPin = 9;
void setup() 
{ 
  myservo.attach(servoPin);
  digitalWrite(ledPin, HIGH);
  pinMode(ledPin, OUTPUT);
  myservo.write(closed);
  myservo.detach();
  Serial.begin(9600);
  
} 
 
void loop() 
{ 
  //analog filter
  for(int i=0;i<10;i++){
    state = state + analogRead(buttonPin);
    delay(3);
  }
  
  if(state > 800){ //High signal, open trashcan;
    myservo.attach(servoPin);
    myservo.write(opened); 
    digitalWrite(ledPin, HIGH);    
  }else{ //Low signal, close trashcan
    myservo.write(closed); 
    myservo.detach();
    digitalWrite(ledPin, LOW);
  }
  state = 0;
  delay(2);
} 

