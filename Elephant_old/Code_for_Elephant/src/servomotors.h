//Library to control servomotors
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#define SERVO0_MIN 173
#define SERVO0_MAX 963

#define SERVO1_MIN 170
#define SERVO1_MAX 962

#define SERVO2_MIN 170
#define SERVO2_MAX 960

#define SERVO3_MIN 170
#define SERVO3_MAX 964

#define SERVO4_MIN 170
#define SERVO4_MAX 964

#define SERVO5_MIN 170
#define SERVO5_MAX 960

#define SERVO6_MIN 170
#define SERVO6_MAX 960

#define SERVO7_MIN 171
#define SERVO7_MAX 965

#define SERVO8_MIN 170
#define SERVO8_MAX 960

#define SERVO9_MIN 170
#define SERVO9_MAX 962

#define SERVO10_MIN 170
#define SERVO10_MAX 960

#define SERVO11_MIN 170
#define SERVO11_MAX 960




Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
void initialize_servomotors()
{
   /* 
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50); 
*/
}
