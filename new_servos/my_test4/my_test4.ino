
#include <ServoDriverSmooth.h>

#define AMOUNT //количество сервомоторов

ServoDriverSmooth servos[12];

//uint32_t timer;//таймер для сервомотора

//примерно то же, но несколько серв


void set_servos_speeds(int servo_speed_1, int servo_speed_2)
{
  servos[0].setSpeed(servo_speed_1);
  servos[1].setSpeed(servo_speed_2);
  Serial.println("Speeds set!");
}
void setup()
{
  Serial.begin(9600);

  Serial.println("setup");


  Serial.println("end setup");
}
void loop()
{

  //set_servos_speeds(5, 80);
  delay(1000);



}
