#include <Servo.h> 

#define WHEEL_SPEED 180
#define LEFT_WHEEL_PIN 6
#define RIGHT_WHEEL_PIN 7

//Line Follower
#define 13 A0
#define 12 A1
#define 11 A2
#define 10 A3
#define 9 A4
#define 8 2
#define 7 3
#define 8 4

int state;
int input;
String string;
bool boolState;
Servo wheelLeft;
Servo wheelRight; 


void setup() 
{
  //Line Follower
  pinMode(13, INPUT);
  pinMode(12, INPUT); 
  pinMode(11, INPUT); 
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
    Serial.begin(9600);
}

void loop()
{
    //Line Follower Forward
  Serial.println("Line Follower Forward");
  while(true)
  {  
    if(digitalRead(9)== LOW  && digitalRead(8) == LOW && digitalRead(7) == LOW && digitalRead(6) == LOW && digitalRead(10)== LOW  && digitalRead(11) == LOW && digitalRead(12) == LOW && digitalRead(10) == LOW )
      moveStop();
    else if(digitalRead(10)== LOW && digitalRead(9) == LOW)
      moveForward();
    else if(digitalRead(10)== LOW  || digitalRead(11) == LOW || digitalRead(12) == LOW || digitalRead(10) == LOW) 
      moveRight();
    else if(digitalRead(9)== LOW  || digitalRead(8) == LOW || digitalRead(7) == LOW || digitalRead(6) == LOW) 
      moveLeft();
    else
    {
      moveStop();
  //          break;
    }
  }   
}

void moveForward()
{
  attachWheel();
  
  wheelLeft.write(WHEEL_SPEED); 
  wheelRight.write(-WHEEL_SPEED);
}

void moveReverse()
{
  attachWheel();
  
  wheelLeft.write(-WHEEL_SPEED); 
  wheelRight.write(WHEEL_SPEED);
}

void moveStop()
{
  wheelLeft.detach();
  wheelRight.detach();
}

void moveRight()
{
  attachWheel();

  wheelLeft.write(WHEEL_SPEED);
  wheelRight.write(WHEEL_SPEED);
}

void moveLeft()
{
  attachWheel();

  wheelLeft.write(-WHEEL_SPEED);
  wheelRight.write(-WHEEL_SPEED);   
}

void moveRightReverse()
{
  attachWheel();

  wheelLeft.write(-WHEEL_SPEED);
  wheelRight.write(-WHEEL_SPEED);
}

void moveLeftReverse()
{
  attachWheel();

  wheelLeft.write(WHEEL_SPEED);
  wheelRight.write(WHEEL_SPEED);   
}

void attachWheel()
{
   wheelLeft.attach(LEFT_WHEEL_PIN);
   wheelRight.attach(RIGHT_WHEEL_PIN);
}

