
#include <ServoDriverSmooth.h>

#define AMOUNT //количество сервомоторов

ServoDriverSmooth servos[12];

//uint32_t timer;//таймер для сервомотора

//примерно то же, но несколько серв
int MAX_theory[] = {963, 962, 960, 964, 964, 960, 960, 965, 960, 962, 960, 960}
int MIN_theiry[] = {173, 170, 170, 170, 170, 170, 171, 170, 170, 170, 170, 170}
int MAX_real[] = {800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800}
int MIN_real[] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200}
void count_average()
{
  
  }
void servos_begin()
  {
  servos[0].attach(0, 275, 825);    // подключить   275 и 825 - для 8 сервомотора для остальных также (я не подбирала)
  servos[1].attach(0, 275, 825);
  servos[2].attach(0, 275, 825);
  servos[3].attach(0, 275, 825);
  servos[4].attach(0, 275, 825);
  servos[5].attach(0, 275, 825);
  servos[6].attach(0, 275, 825);
  servos[7].attach(0, 275, 825);
  servos[8].attach(0, 275, 825);
  servos[9].attach(0, 275, 825);
  servos[10].attach(0, 275, 825);
  servos[11].attach(0, 275, 825);
  delay(100);
  }

void set_servos_speeds(int *speeds_array)
{
  for(byte i = 0; i < 12; i++)
  {
    servos[i].setSpeed(speeds_array[i]);
    Serial.print(String(speeds_array[i])+' ');
    }
  Serial.println("Speeds set!");
  
}
/*void servos_go(int servos_angles[], int servos_speeds[],float servos_accels = [0,0,0,0,0,0,0,0,0,0,0,0]) //поворачивает до заданного угла с заданной скоростью и ускорением
  {
  Serial.println("begin servos_go!");

  Serial.println("Angle = " + String(servo_angle) + " Speed = " + String(servo_speed) + " Accel = " + String(servo_accel));

  servo.setAccel(servo_accel); //заданное ускорение (по умолчанию 0)
  while (abs(servo.getCurrentDeg() - servo_angle) > 2)
  {
    servo.tick();
    servo.setTargetDeg(servo_angle);
  }
  Serial.println("end servos_go!");


  void servo_go(int servo_angle, int servo_speed, float servo_accel=0.0) //поворачивает до заданного угла с заданной скоростью и ускорением
  {
  Serial.println("begin servo_go!");
  Serial.println("Angle = " + String(servo_angle) + " Speed = " + String(servo_speed) + " Accel = " + String(servo_accel));
  servo.setSpeed(servo_speed); //заданная скорость
  servo.setAccel(servo_accel); //заданное ускорение (по умолчанию 0)
  while (abs(servo.getCurrentDeg() - servo_angle) > 2)
  {
    servo.tick();
    servo.setTargetDeg(servo_angle);
  }
  Serial.println("end servo_go!");

  }
  }*/
void setup()
{
  Serial.begin(9600);

  Serial.println("setup");


  Serial.println("end setup");
}
void loop()
{
int array1 []= {0,0,0,0,0,0,8,8,4,6,7,3};
  set_servos_speeds(array1);
  delay(1000);



}
