#include <Arduino.h>

#include <calibration.h>
#define SERVO0_AVG 610
#define SERVO1_AVG 615
#define SERVO2_AVG 650
#define SERVO3_AVG 600
#define SERVO4_AVG 620
#define SERVO5_AVG 650
#define SERVO6_AVG 620
#define SERVO7_AVG 600
#define SERVO8_AVG 630
#define SERVO9_AVG 650
#define SERVO10_AVG 600
#define SERVO11_AVG 200

int pos=400;
void setup()
{
  // interrupt # 0, pin 2
  initialize_winch();
  
  pwm.begin(); //Объявление объекта pwm

//  pwm.setOscillatorFrequency(27000000);
 pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  delay(10);
  Serial.begin(9600);
  winch_homing();
  delay(3000);
  
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!




void loop()
{
  int t = 0;
  int enc = 0;
  float f = 0;
  float h = 0; 
  
  move_winch(300);
  // while(done==0)move_winch(300);
  // delay(2000);
  // done=0;
  // while(done==0)move_winch(100);
  // delay(2000);
  // done=0;
  // while(done==0)move_winch(200);
  // delay(2000);
  // done=0;
  // for (int i = 0; i < 400; i++) 
  // {
  //   while(!done)move_winch(i);
    
  // }
  // for (int i = 400; i < 0; i--) 
  // {
  //   while(!done)move_winch(i);
  // }


 /* while (abs(enc) < 300)
  {
      motor_lebedka(-100);
   
    Serial.println(enc);
    t++;
  delay(1);
  }
 */

 
     /*while (enc > 0)
  {
    
    motor_lebedka(80);
 
    Serial.println(enc);
  delay(1);
  Enc();
 
  }*/
//  Serial.println("test servo");
//  pwm.setPWM(0,0,SERVO0_AVG);
//  pwm.setPWM(1,0,SERVO1_AVG);
//  pwm.setPWM(2,0,SERVO2_AVG);
//  pwm.setPWM(3,0,SERVO3_AVG);
//  pwm.setPWM(4,0,SERVO4_AVG);
//  pwm.setPWM(5,0,SERVO5_AVG);
//  pwm.setPWM(6,0,SERVO6_AVG);
//  pwm.setPWM(7,0,SERVO7_AVG);
//  pwm.setPWM(8,0,SERVO8_AVG);
//  pwm.setPWM(9,0,SERVO9_AVG);
//  pwm.setPWM(10,0,SERVO10_AVG);
//  pwm.setPWM(11,0,SERVO11_AVG);
//  delay(100);
 //Serial.println("ready");

// Serial.println("0 servo");
// pwm.setPWM(1,0, 566);
// Serial.println("1 servo");
// pwm.setPWM(2,0, 565);
// Serial.println("2 servo");
// delay(2000);

}