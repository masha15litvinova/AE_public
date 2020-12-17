/*
   Данный код плавно двигает туда-сюда одной сервой
   Используется драйвер PCA9685 
   Документация: https://alexgyver.ru/servosmooth/
*/

#include <ServoDriverSmooth.h>
ServoDriverSmooth servo;
//ServoDriverSmooth servo(0x40);      // с указанием адреса драйвера
//ServoDriverSmooth servo(0x40, 270); // с указанием адреса и макс. угла

uint32_t tmr;
boolean flag;

void setup() {
  Serial.begin(9600);
  
  Serial.println("setup");
  servo.attach(8, 275, 825, 0);    // подключить
  
  servo.setSpeed(60); // ограничить скорость
  servo.setAccel(0.9);   // установить ускорение (разгон и торможение)
  servo.setDirection(false);
  Serial.println("end setup");
}

void loop() {
  servo.tick();

  if (millis() - tmr >= 3000) {   // каждые 3 сек
    tmr = millis();
    servo.setTargetDeg(70);  // двигаем на углы 50 и 120
  }
}
