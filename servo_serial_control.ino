#include <Servo.h>

Servo servoBase;

Servo servoArm1;
Servo servoArm2;

Servo servoTopArm1;
Servo servoTopArm2;

Servo servoHead;

Servo servoHand;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo serial control");
  servoArm1.attach(3);
  servoArm2.attach(5);

  servoBase.attach(7);

  servoTopArm1.attach(8);
  servoTopArm2.attach(9);

  servoHead.attach(10);
  servoHand.attach(11);
  
  armCenter();
  topArmCenter();
}

void loop() {
  String data = Serial.readString();
  Serial.println(data);

  if(data.indexOf("ba45f")>=0){ // bottom arm forward 45 degrees
      arm45Forward();
  }else if(data.indexOf("ba45b")>=0){ // bottom arm backwards 45 degrees
    arm45Backwards();
  }
  else if(data.indexOf("baf")>=0){ // bottom arm forward
      armMaxForward();
  }else if(data.indexOf("bab")>=0){ // bottom arm backwards
    armMaxBackwards();
  }else if(data.indexOf("bac")>=0){ // bottom arm center
    armCenter();
  }else if(data.indexOf("hg")>=0){ // hand grab
    handGrab();
  }
  else if(data.indexOf("hrel")>=0){ // hand release
    handRelease();
  }else if(data.indexOf("taf")>=0){ // top arm forward
      topArmMaxForward();
  }else if(data.indexOf("tab")>=0){ // top arm backwards
    //topArmMaxBackwards();
  }
  else if(data.indexOf("ta45f")>=0){ // top arm forward
      topArm45Forward();
  }else if(data.indexOf("tac")>=0){ // top arm center
    topArmCenter();
  }else if(data.indexOf("bc")>=0){ // base center
    baseCenter();
  }else if(data.indexOf("br")>=0){ // base right
    baseRight();
  }else if(data.indexOf("bl")>=0){ // base left
    baseLeft();
  }else if(data.indexOf("hr")>=0){ // head right
    headRight();
  }else if(data.indexOf("hl")>=0){ // head left
    headLeft();
  }
  else if(data.indexOf("hc")>=0){ // head center
    headCenter();
  }
  
  
}
void arm45Forward(){
  servoArm1.write(135);
  servoArm2.write(45);
    
}
void arm45Backwards(){
  servoArm1.write(45);
  servoArm2.write(135);
    
}

void armMaxForward(){
  servoArm1.write(180);
  servoArm2.write(0);
    
}
void armMaxBackwards(){
  servoArm1.write(0);
  servoArm2.write(180);
    
}
void armCenter(){
  servoArm1.write(90);
  servoArm2.write(90);
}
void baseCenter(){
  servoBase.write(90);
}
void baseLeft(){
  servoBase.write(180);
}
void baseRight(){
  servoBase.write(0);
}
void topArmMaxForward(){
  servoTopArm1.write(180);
  servoTopArm2.write(0);
    
}
//void topArmMaxBackwards(){
//  servoTopArm1.write(0);
//  servoTopArm2.write(180);
//    
//}
void topArm45Forward(){
  servoTopArm1.write(135);
  servoTopArm2.write(45);
}
void topArmCenter(){
  servoTopArm1.write(90);
  servoTopArm2.write(90);
}

void headCenter(){
  servoHead.write(90);
}
void headLeft(){
  servoHead.write(180);
}
void headRight(){
  servoHead.write(0);
}
void handRelease(){
  servoHand.write(65);
}
void handGrab(){
  servoHand.write(180);
}
