String command, target, value;
float intval;

#include <Servo.h>

Servo browServo;  
Servo mouthServo;
Servo twistServo;
Servo tiltServo;

int browUp = 0; 
int browDown = 35;

int mouthOpen = 00;
int mouthClosed = 30;
int deltime = 2000;
int left = 45;
int right = 0;
int up = 180 ;
int down = 0;

int leftLED = A0;
int rightLED = A1;

void setup() {
  Serial.begin(9600);
  twistServo.attach(8);
  browServo.attach(10);
  mouthServo.attach(9);
  tiltServo.attach(11);
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

  browServo.write(browUp);
  mouthServo.write(mouthClosed);
  twistServo.write(left);
  tiltServo.write(down);
  digitalWrite(leftLED, LOW);
  digitalWrite(rightLED, LOW);


}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    target = command.substring(0, 1);
    value = command.substring(1);
    intval = value.toFloat();
//    Serial.print("Command: ");
//    Serial.println(target);
//
//    Serial.print("value: ");
//    Serial.println(intval);

    if (target.equals("L")) {
      if(intval == 1.0)
      {
          digitalWrite(leftLED, HIGH);
          Serial.print("Turning Left Eye On. ");
      }
      else
      {
          digitalWrite(leftLED, LOW);
          Serial.print("Turning Left Eye Off. ");
      }
    }
    else if (target.equals("R")) {
       if(intval == 1.0)
      {
          digitalWrite(rightLED, HIGH);
          Serial.print("Turning right Eye On. ");
      }
      else
      {
          digitalWrite(rightLED, LOW);
          Serial.print("Turning right Eye Off. ");
      }
    }
    else if (target.equals("P")) {
      int writeVal = (abs(left-right))*intval + right; // assuming right is zero
      twistServo.write(writeVal);
      Serial.print("Updating Pan to ");
      Serial.println(writeVal);
    }
    else if (target.equals("T")) {
       int writeVal = (abs(up-down))*intval + down; // assuming down is zero
      tiltServo.write(writeVal);
      Serial.print("Updating tilt to ");
      Serial.println(writeVal);
    }
    else if (target.equals("B")) {
      if(intval <=0.5)
      {
        browServo.write(browDown);
        Serial.println("Updating eyebrows to angry");
      }
      
      if(intval > 0.5)
      {
        browServo.write(browUp);
        Serial.println("Updating eyebrows to surprised");
      }
    }
    else if (target.equals("M")) {
       if(intval <=0.5)
      {
        mouthServo.write(mouthClosed);
        Serial.println("Closing Mouth");
      }
      
      if(intval > 0.5)
      {
        mouthServo.write(mouthOpen);
        Serial.println("Opening Mouth");
      }
    }
    //
    else if (target.equals("N")) {
      int nodtime = 300;
      Serial.println("Nodding");
      tiltServo.write(up);
      delay(nodtime );
      tiltServo.write(down);
      delay(nodtime );
      tiltServo.write(up);
      delay(nodtime );
      tiltServo.write(down);
       delay(nodtime );
      tiltServo.write(up);
      delay(nodtime );
      tiltServo.write(down);
       delay(nodtime );
      tiltServo.write(up);
      delay(nodtime );
      tiltServo.write(down);
    }
    //
    else if (target.equals("S")) {
      int nodtime = 300;
      Serial.println("Shaking");
      twistServo.write(left);
      delay(nodtime );
      twistServo.write(right);
      delay(nodtime );
      twistServo.write(left);
      delay(nodtime );
      twistServo.write(right);
       delay(nodtime );
      twistServo.write(left);
      delay(nodtime );
      twistServo.write(right);
       delay(nodtime );
      twistServo.write(left);
      delay(nodtime );
      twistServo.write(right);
    }
    else if (target.equals("J")) {
      int nodtime = 300;
      Serial.println("jabbering");
      mouthServo.write(mouthClosed);
      delay(nodtime );
      mouthServo.write(mouthOpen);
      delay(nodtime );
      mouthServo.write(mouthClosed);
      delay(nodtime );
      mouthServo.write(mouthOpen);
       delay(nodtime );
      mouthServo.write(mouthClosed);
      delay(nodtime );
      mouthServo.write(mouthOpen);
       delay(nodtime );
      mouthServo.write(mouthClosed);
      delay(nodtime );
      twistServo.write(right);
    }
  }
}
