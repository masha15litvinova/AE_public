//Library to control servomotors
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>



Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
void initialize_servomotors()
{
   /* 
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50); 
*/
}
