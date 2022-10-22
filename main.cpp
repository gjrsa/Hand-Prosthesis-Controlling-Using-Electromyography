#include <Arduino.h>
#include <Uart.h>
#include <nrf.h>
#include "HardwareSerial.h"
#include "Plotter.h"

#define sensor 28
#define TX 16
#define RX 17
#define LED_BUILTIN_G 10
#define EMG 5
#define SWO 18
#define SWDCLK SWDCLK
#define SWDIO SWDIO

double emg = 0;

double x;
double y;

Plotter p;

void setup() {
  pinMode(LED_BUILTIN_G, OUTPUT);
  pinMode(EMG, OUTPUT);
  Serial.setPins(RX, TX);
  Serial.begin(115200);

//   p.Begin();
//   p.AddXYGraph( "X-Y graph w/ 500 points", 500, "x axis", x, "y axis", y );
//   p.AddXYGraph( "X-Y graph w/ 200 points", 200, "x axis", x, "y axis", y );

//   p.AddTimeGraph( "Time graph w/ 500 points", 500, "x label", x );
//   p.AddTimeGraph( "Time graph w/ 200 points", 200, "x label", x );

  Serial.println("Hello World mRF52832");
  delay(1000);
}

void loop() {
  digitalWrite(LED_BUILTIN_G, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN_G, LOW);
  delay(500);
  emg = analogRead(EMG);
  Serial.println(emg);
  delay(100);

//   x = 10*sin( 2.0*PI*( millis() / 5000.0 ) );
//   y = 10*cos( 2.0*PI*( millis() / 5000.0 ) );

//   p.Plot();
}

// void setup()
// {
//     // Start plotter
//     p.Begin();
  
//     // Add X-Y graphs 
//     p.AddXYGraph( "X-Y graph w/ 500 points", 500, "x axis", x, "y axis", y );
//     p.AddXYGraph( "X-Y graph w/ 200 points", 200, "x axis", x, "y axis", y );

//     // Add time graphs. Notice the effect of points displayed on the time scale
//     p.AddTimeGraph( "Time graph w/ 500 points", 500, "x label", x );
//     p.AddTimeGraph( "Time graph w/ 200 points", 200, "x label", x );

// }

// void loop()
// {
//     // Update variables with arbitrary sine/cosine data
//     x = 10*sin( 2.0*PI*( millis() / 5000.0 ) );
//     y = 10*cos( 2.0*PI*( millis() / 5000.0 ) );

//     // Plot
//     p.Plot();
// }