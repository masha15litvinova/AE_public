
#include <ServoDriverSmooth.h>

#define AMOUNT //количество сервомоторов

ServoDriverSmooth servos[12];

//uint32_t timer;//таймер для сервомотора

//примерно то же, но несколько серв
int MAX_theory[] = {963, 962, 960, 964, 964, 960, 960, 965, 960, 962, 960, 960};   //теоретический максимум для самого сервомотора
int MIN_theory[] = {173, 170, 170, 170, 170, 170, 171, 170, 170, 170, 170, 170};   //теоретический минимум для самого сервомотора
int MAX_real[] = {800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800};     //куда серва реально может повернуться, чтобы лапа не сломалась максимум
int MIN_real[] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200};     //куда серва реально может повернуться, чтобы лапа не сломалась минимум
void count_average()
{
  int AVG_theory[12];
  int AVG_real[12];
  Serial.println(" ");
  Serial.println("AVG_theory:");
  for (byte i = 0; i < 12; i++)
  {
    AVG_theory[i] = (MAX_theory[i] + MIN_theory[i]) / 2;
    Serial.print(String(AVG_theory[i]) + " ");
  }
  Serial.println("");
  Serial.println("AVG_real:");
  for (byte i = 0; i < 12; i++)
  {
   
    AVG_real[i] = (MAX_real[i] + MIN_real[i]) / 2;
    Serial.print(String(AVG_real[i]) + " ");
  }
}
void servos_begin() //инициализация всех сервомоторов (минимум максимум)
{
  count_average();
  Serial.println(" ");
  Serial.println("Servos begin!");
  for (byte i = 0; i < 12; i++)
  {
    
    servos[i].attach(i, MIN_real[i], MAX_real[i]);
    Serial.println("Servo " + String(i) + " attached on " + String(MIN_real[i]) + " = min " + String(MAX_real[i]) + " = max");
  }
  delay(100);
}

void set_servos_speeds(int *speeds_array) //задание скоростей всем 12 сервам через массив
{
  Serial.println(" ");
  Serial.println("Speeds:");
  for (byte i = 0; i < 12; i++)
  {
    servos[i].setSpeed(speeds_array[i]);
    Serial.print(String(speeds_array[i]) + " ");
  }
  

}
void set_servos_accels(int *accels_array) //задание ускорений всем 12 сервам через массив
{
  Serial.println(" ");
  Serial.println("Accels:");
  for (byte i = 0; i < 12; i++)
  {
    servos[i].setAccel(accels_array[i]);
    Serial.print(String(accels_array[i]) + " ");
  }
  

}
void  servos_go(int *angles_array)
{
  Serial.println(" ");
  Serial.println("Angles:");
  for (byte i = 0; i < 12; i++)
  {
    Serial.print(String(angles_array[i]) + " ");
    }
   bool canRun = true;
   while(canRun)
   {
    canRun = 1
    servos_end_count = 0; //количество сервомоторо, чье движение закончено
    for (byte i = 0; i < 12; i++)
    {
      
      }
    }
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
servos_begin();
  
  int array1 [] = {0, 0, 0, 0, 0, 0, 8, 8, 4, 6, 7, 3};
  set_servos_accels(array1);
  delay(1000);



}
