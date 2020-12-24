/*void servos_begin()
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
  }*/

/*int set_servos_speeds(speed_servo_0, speed_servo_1)
{
  servos[0].setSpeed(speed_servo_0);
  servos[1].setSpeed(speed_servo_1);
  Serial.println("Speeds set!");
}*/
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
