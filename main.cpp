#include <myo.h>

#define ONBOARD_LED  2

armband myo; // Myo BLE Armband

// Serial
void print_emg_sample(int8_t *sample, size_t len)
{
  for (int i = 0; i < len; i++)
  {
    Serial.print(sample[i]);
    Serial.print("\t");
  }
  Serial.println();
}

// Read EMG Myo
void emg_callback(BLERemoteCharacteristic *pBLERemoteCharacteristic, uint8_t *pData, size_t length, bool isNotify)
{
  myohw_emg_data_t *emg_data = (myohw_emg_data_t *)pData;
  print_emg_sample(emg_data->sample1, myohw_num_emg_sensors);
  print_emg_sample(emg_data->sample2, myohw_num_emg_sensors);
}

// Connect Myo
void myo_connect()
{
  Serial.println("Connecting...");
  myo.connect();
  Serial.println(" - Connected");
  delay(100);

  myo.set_myo_mode(myohw_emg_mode_send_emg,         // EMG mode send_emg none
                   myohw_imu_mode_none,             // IMU mode send_data none
                   myohw_classifier_mode_disabled); // Classifier mode enable disable

  myo.emg_notification(TURN_ON)->registerForNotify(emg_callback);
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (!myo.connected)
  {
    myo_connect();
  }
  delay(10);
}
