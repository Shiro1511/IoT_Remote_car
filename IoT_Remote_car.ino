#include <AFMotor.h>
  
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
  
int val;
int Speeed = 255;
  
void setup()
{
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}
void loop(){
  if(Serial.available() > 0){
    val = Serial.read();
      
    Stop(); //initialize with motors stoped
      
          if (val == 'F'){
          forward();
          }
  
          if (val == 'B'){
          back();
          }
  
          if (val == 'L'){
          left();
          }
  
          if (val == 'R'){
          right();
          }
          if (val == 'I'){
          topright();
          }
  
          if (val == 'J'){
          topleft();
          }
  
          if (val == 'K'){
          bottomright();
          }
  
          if (val == 'M'){
          bottomleft();
          }
          if (val == 'T'){
          Stop();
          }
  }
}

void forward()
{
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);
}
  
void back()
{
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
}
  
void left()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
}
  
void right()
{
  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);
}
  
void topleft(){
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor3.setSpeed(Speeed/3.1);
  motor3.run(FORWARD);
}
  
void topright()
{
  motor2.setSpeed(Speeed/3.1);
  motor2.run(FORWARD);
  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);

}
  
void bottomleft()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);
  motor4.setSpeed(Speeed/3.1);
  motor4.run(FORWARD);
}
  
void bottomright()
{
  motor2.setSpeed(Speeed/3.1);
  motor2.run(FORWARD);
  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
}
  
  
void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
