#ifndef winch_h_
#define winch_h_

#define MOTORw_EN 24
#define MOTORw_INA1 25
#define MOTORw_INB1 26
#define MOTORw_PWM 46

#define WINCH_ENC1 19
#define WINCH_ENC2 18

#define WINCH_CS A6

#include <Arduino.h>

int winch_dir = 0;
volatile long winch_enc = 0;
int length = 0;
int stepsPerRevolution = 1500;
int winch_diameter = 32;



void motor_winch(int pwm_value)
{
  if (pwm_value > 255)
  {
    pwm_value = 255;
    winch_dir = 1;
  }

  if (pwm_value < -255)
  {
    pwm_value = -255;
    winch_dir = -1;
  }

  if (pwm_value > 0)
  {
    digitalWrite(MOTORw_EN, HIGH);
    digitalWrite(MOTORw_INA1, HIGH);
    digitalWrite(MOTORw_INB1, LOW);
    analogWrite(MOTORw_PWM, pwm_value);
  }
  else if (pwm_value==0)
  {
    digitalWrite(MOTORw_EN, HIGH);
    digitalWrite(MOTORw_INA1, HIGH);
    digitalWrite(MOTORw_INB1, HIGH);
    analogWrite(MOTORw_PWM, pwm_value);
  }
  else
  {
    pwm_value = pwm_value * (-1);
    digitalWrite(MOTORw_EN, HIGH);
    digitalWrite(MOTORw_INA1, LOW);
    digitalWrite(MOTORw_INB1, HIGH);
    analogWrite(MOTORw_PWM, pwm_value);
  }
}

// void winchEncoderEvent() {
//   if (digitalRead(WINCH_ENC1) == HIGH) {
//     if (digitalRead(WINCH_ENC2) == LOW) {
//       winch_enc++;
//     } else {
//       winch_enc--;
//     }
//   } else {
//     if (digitalRead(WINCH_ENC2) == HIGH) {
//       winch_enc--;
//     } else {
//       winch_enc++;
//     }
//   }
// }

void winchEncoderEvent1() {
  // look for a low-to-high on channel A
  if (digitalRead(WINCH_ENC1) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(WINCH_ENC2) == LOW) {
      winch_enc++;         // CW
    }
    else {
      winch_enc--;         // CCW
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(WINCH_ENC2) == HIGH) {
      winch_enc++;          // CW
    }
    else {
      winch_enc--;          // CCW
    }
  }

}

void winchEncoderEvent2() {
  // look for a low-to-high on channel B
  if (digitalRead(WINCH_ENC2) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(WINCH_ENC1) == HIGH) {
      winch_enc++;         // CW
    }
    else {
      winch_enc--;         // CCW
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(WINCH_ENC1) == LOW) {
      winch_enc++;          // CW
    }
    else {
      winch_enc--;          // CCW
    }
  }
}
float winchGetLength()
{
  length=((3.1415*winch_diameter)/stepsPerRevolution) * winch_enc;
  return length;
}

void winch_homing()
{
  int winch_current;
  //motor_winch(50);
  //delay(50);
  do
  {
    winch_current=analogRead(WINCH_CS);
      //Serial.println("winch_current:");
      Serial.print(winch_current);
      motor_winch(60);
      delay(100);
  } while(analogRead(WINCH_CS)<110);
  motor_winch(0);
}

void initialize_winch()
{
  pinMode(MOTORw_EN, OUTPUT);
  pinMode(MOTORw_INA1, OUTPUT);
  pinMode(MOTORw_INB1, OUTPUT);
  pinMode(MOTORw_PWM, OUTPUT);

  pinMode(WINCH_ENC1,INPUT);
  pinMode(WINCH_ENC2,INPUT);

  pinMode(WINCH_CS,INPUT);

  attachInterrupt(digitalPinToInterrupt(WINCH_ENC1), winchEncoderEvent1 , CHANGE);
  attachInterrupt(digitalPinToInterrupt(WINCH_ENC2), winchEncoderEvent2 , CHANGE);
}
#endif