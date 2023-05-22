void myo_connect()
{
  Serial.println("Connecting...");
  myo.connect();
  Serial.println(" - Connected");
  delay(100);

  myo.set_myo_mode(myohw_emg_mode_send_emg,    
                   myohw_imu_mode_send_data,           
                   myohw_classifier_mode_disabled);

  // myo.battery_notification(TURN_ON)->registerForNotify(batteryCallback);
  // myo.imu_notification(TURN_ON)->registerForNotify(imu_callback);
   myo.emg_notification(TURN_ON)->registerForNotify(emg_callback);
}



