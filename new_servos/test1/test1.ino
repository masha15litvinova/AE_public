/*
   Данный код плавно управляет одной сервой   
   при помощи потенциометра (на пине А0).
   Используется драйвер PCA9685
   Откройте порт по последовательному соединению для наблюдения за положением серво
   Документация: https://alexgyver.ru/servosmooth/
*/
#include "ServoDriverSmooth.h"
//uServoDriverSmooth servo(270);
//ServoDriverSmooth servo(0x40);      // с указанием адреса драйвера
ServoDriverSmooth servo(0x40, 270); // с указанием адреса и макс. угла
uint32_t myTimer;
void setup() {
  Serial.begin(9600);
  servo.attach(8, 170, 960);  // 150 и 600 - длины импульсов, при которых
  // серво поворачивается максимально в одну и другую сторону, зависят от самой серво
  // и обычно даже указываются продавцом. Мы их тут указываем для того, чтобы
  // метод setTargetDeg() корректно отрабатывал диапазон поворота сервы
  // для драйвера диапазон в районе 150-600! Не как у обычной серво
  servo.setSpeed(20);    // ограничить скорость
  servo.setAccel(0.5);    // установить ускорение (разгон и торможение)
}
void loop() {
  // желаемая позиция задаётся методом setTarget (импульс) или setTargetDeg (угол), далее
  // при вызове tick() производится автоматическое движение сервы
  // с заданным ускорением и ограничением скорости
  boolean state = servo.tick();   // здесь происходит движение серво по встроенному таймеру!
  if (millis() - myTimer >= 40) {
    myTimer = millis();
    int newPos = 100; // берём с потенцометра значение 0-180
    servo.setTargetDeg(newPos);                       // и отправляем на серво
    Serial.println(String(newPos) + " " + String(servo.getCurrentDeg())/* + " " + String(state)*/);
  // state показывает сотояние сервы (0 - движется, 1 - приехали и отключились)
  }
}
