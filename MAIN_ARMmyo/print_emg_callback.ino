void print_emg_callback(int8_t *sample, size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (sample[i] < 0)
      sample[i] = 0;

    if (sample[1] > 10 && sample[2] > 10){
      digitalWrite(led1, HIGH);
    }
    if (sample[3] > 10 && sample[4] > 10){
      digitalWrite(led2, HIGH);
    }
    if (sample[1] < 10 && sample[2] < 10 && sample[3] < 10 && sample[4] < 10){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }

    if (sample[0] > 60 ){
      chack--;
      delay(10);
    }
    
    else if (sample[5] > 60 ){
      chack++;
      delay(10);
    }
    // Serial.print("T1 ");
    Serial.print(sample[i]);
    Serial.print("\t");
  }
  Serial.print(chack);
  Serial.print("\t");
  digitalWrite(ONBOARD_LED,LOW);
  Serial.println();

  if(chack >= 40){
    chack = 40;
    move = 1;
  }
  if(chack <= 0){
    chack = 0;
    move = 0;

  }
  if(move == 0){ //bear
    digitalWrite(ONBOARD_LED,HIGH);
    pwm.setPWM(10, 0, pulseWidth(0));
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
  else if(move == 1){
    digitalWrite(ONBOARD_LED,HIGH);
    pwm.setPWM(10, 0, pulseWidth(180));
    pwm.setPWM(1, 0, pulseWidth(90));
    pwm.setPWM(0, 0, pulseWidth(110));
    pwm.setPWM(2, 0, pulseWidth(45));
    pwm.setPWM(3, 0, pulseWidth(85));
    pwm.setPWM(4, 0, pulseWidth(105));
    pwm.setPWM(5, 0, pulseWidth(63));
    pwm.setPWM(7, 0, pulseWidth(85));
    pwm.setPWM(11, 0, pulseWidth(85));
    pwm.setPWM(8, 0, pulseWidth(110));
    pwm.setPWM(9, 0, pulseWidth(70));
  }
}






