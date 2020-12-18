
#include <ServoDriverSmooth.h>
ServoDriverSmooth servo;

uint32_t timer;//таймер для сервомотора

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



  servo_go(60, 60, 0.9);
  delay(1000);
 Serial.println("1");
  servo_go(20, 40);
  delay(1000);
  Serial.println("2");
  
}
