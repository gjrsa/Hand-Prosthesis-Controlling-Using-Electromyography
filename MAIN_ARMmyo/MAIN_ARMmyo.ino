#include <myo.h>
#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
#define MIN_PULSE_WIDTH 600
#define MAX_PULSE_WIDTH 2600
#define FREQUENCY 50
#define ONBOARD_LED  2

int led1 = 32;
int led2 = 33; 
int led3 = 25;
int led4 = 26;
int led5 = 27;
int led6 = 14;
int chack = 0;
int move = 0;
int chack1 = 0;
int move1 = 0;
char READ;
int read1 = 1;

armband myo; 

void setup()
{
  Serial.begin(115200);
  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  pinMode(ONBOARD_LED, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

      pwm.setPWM(10, 0, pulseWidth(0));
      delay(200);
      pwm.setPWM(1, 0, pulseWidth(180));
      pwm.setPWM(0, 0, pulseWidth(100));
      pwm.setPWM(2, 0, pulseWidth(180));
      pwm.setPWM(3, 0, pulseWidth(160));
      pwm.setPWM(4, 0, pulseWidth(170));
      pwm.setPWM(5, 0, pulseWidth(160));
      pwm.setPWM(7, 0, pulseWidth(140));
      pwm.setPWM(11, 0, pulseWidth(180));
      pwm.setPWM(8, 0, pulseWidth(180));
      pwm.setPWM(9, 0, pulseWidth(180));
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void loop()
{
  if (!myo.connected)
  {
    myo_connect();
  }
  delay(100); 
}