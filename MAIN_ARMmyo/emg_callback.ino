void emg_callback(BLERemoteCharacteristic *pBLERemoteCharacteristic, uint8_t *pData, size_t length, bool isNotify)
{
  myohw_emg_data_t *emg_data = (myohw_emg_data_t *)pData;
  print_emg_callback(emg_data->sample1, myohw_num_emg_sensors);
  print_emg_callback(emg_data->sample2, myohw_num_emg_sensors);
}


