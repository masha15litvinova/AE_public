
#include <ServoDriverSmooth.h>
ServoDriverSmooth servo;

uint32_t timer;//таймер для сервомотора

void servo_go(int servo_angle, int servo_speed, int servo_accel = 0.0) //поворачивает до заданного угла с заданной скоростью и ускорением
{ 

  servo.tick();
  servo.setSpeed(servo_speed); //заданная скорость
  servo.setAccel(servo_accel); //заданное ускорение (по умолчанию 0)
  servo.setTargetDeg(servo_angle); //целевое значение угла
}
void setup()
{
  Serial.begin(9600);

  Serial.println("setup");

  servo.attach(8, 275, 825);    // подключить

  servo.setSpeed(60); // ограничить скорость
  servo.setAccel(0.9);   // установить ускорение (разгон и торможение)
  delay(2000);
  Serial.println("end setup");
}
void loop()
{



  servo_go(10, 60, 0.9);
  Serial.println("go 10");
  delay(1000);
  servo_go(50,30);
  Serial.println("go 50");
  delay(1000);
}
