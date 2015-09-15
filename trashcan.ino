/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int closed = 0;
int opened = 140;
int state = 0;
const int buttonPin = 2;
const int ledPin =  13; 
const int servoPin = 9;
void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
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
  Serial.println(analogRead(buttonPin));
  delay(2);
} 

