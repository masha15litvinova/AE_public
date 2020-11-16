//library for start position

#include <checking.h>
void start_servomotors()
{
    pwm.setPWM(0, 0,567);
    pwm.setPWM(1, 0,566);
    pwm.setPWM(2, 0,565);
    pwm.setPWM(3, 0,567);
    pwm.setPWM(4, 0,567);
    pwm.setPWM(5, 0,565);
    pwm.setPWM(6, 0,565);
    pwm.setPWM(7, 0,568);
    pwm.setPWM(8, 0,565);
    pwm.setPWM(9, 0,566);
    pwm.setPWM(10, 0,565);
    pwm.setPWM(11, 0,565);
    delay(10000);
}

void start_winch()
{
    //калибровка лебедки по току

}

void start_platform()
{
    //запоминание положения маркера, обнуление гироскопа и всех переменных

}

void start_display()
{
    //очистка и перезагрузка дисплея, вывод нужного текста

}
