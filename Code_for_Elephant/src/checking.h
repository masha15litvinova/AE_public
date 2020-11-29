//Library to check all mechanics
#include <Arduino.h>
#include <omni_platform.h>
#include <servomotors.h>
#include <winch.h>


void check_motors(int h)
{
    for (int i = 0; i < h; i++)
    {
        //check 1 motor
        motors(70, 0, 0, 0);
        delay(1000);
        motors(0, 0, 0, 0);
        //check 1 motor: reverse
        motors(-70, 0, 0, 0);
        delay(1000);
        motors(0, 0, 0, 0);
       ///check 2 motor
        motors(0, 70, 0, 0);
        delay(1000);
        motors(0, 0, 0, 0);
        //check 2 motor: reverse
        motors(0, -70, 0, 0);
        delay(1000);
        motors(0, 0, 0, 0);
        //check 3 motor
        motors(0, 0, 70, 0);
        delay(1000);
        motors(0, 0, 0, 0);
        //check 3 motor: reverse
        motors(0, 0, -70, 0);
        delay(1000);
        motors(0, 0, 0, 0);
        //check 4 motor
        motors(0, 0, 0, 70);
        delay(1000);
        motors(0, 0, 0, 0);
        //check 4 motor: reverse
        motors(0, 0, 0, -70);
        delay(1000);
        motors(0, 0, 0, 0);
    }

}

void check_display()
{
    

}