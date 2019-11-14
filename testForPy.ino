#include <SCoop.h>

#include <Servo.h>

Servo servoRudder;
Servo servoSail;
int receive=Serial.parseInt();

  

void setup() {
  servoSail.attach(9);
  servoRudder.attach(10);
  mySCoop.start();
  Serial.begin(9600);
  
  while(Serial.read()>= 0){}
}


void loop() {
  yield();
}

//开启多线程
defineTask(Rudder);
defineTask(Sail);


void Rudder::setup (){
  pinMode(10,OUTPUT);
}
void Rudder::loop(){
  if (receive > 180) {
    int angleForRudder = receive - 360;
    servoRudder.write(angleForRudder);
    sleep(5000);
  while(Serial.read()>=0){}} 
  else{ servoRudder.write(0);
  sleep(1000);
  }
}


//帆部分
void Sail::setup(){
  pinMode(9,OUTPUT);
}
void Sail::loop(){
  if (receive <= 180){
    servoSail.write(receive);
    sleep(5000);
    while(Serial.read()>=0){}
  } else {servoSail.write(0);
  sleep(1000);
}
}
  
