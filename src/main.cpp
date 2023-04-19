#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <set_register.h>
#include <refresh_sensor_readings.h>
#include <time_keeper.h>
#include <data_logger.h>



void setup()
{
  Serial.begin(9600);

  dht.begin();

  // Set all the pins of 74HC595 as OUTPUT
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_OUT_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  Wire.begin(D2, D1);

  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1)
      ;
  }

  if (!rtc.isrunning())
  {
    Serial.println("RTC is NOT running!");
    // Set the RTC to the current date and time (change these values to the current date and time)
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}


void loop()
{
  byte OUTPUTS = 0; // Initially turns all the outputs off
  setShiftRegister(OUTPUTS);
  delay(500);
  for (int i = 1; i <= 2; i++) // Begin iterating through the outputs
  {
    OUTPUTS = 1 << i; // Set the bit that controls that output in the variable 'OUTPUTS'
    setShiftRegister(OUTPUTS);
    delay(1000);
    refreshReadings();
    delay(300);
  }
}

// LogData getData()
    // {

    //   // Read RTC
    //   // DateTime now = rtc.now();
    //   // delay(1000);

    //   // // Format the timestamp
    //   // char format[] = "DD-MM-YYYY hh:mm:ss";
    //   // String ts = now.toString(format);
    //   // Serial.println(ts);
    //   // Serial.println(now.toString(format));
    //   // String ts = now.day() + "-" + String(now.month()) + "-" + String(now.year()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());

    //   // Check if any reads failed and exit early (to try again).
    //   if (isnan(h) || isnan(t))
    //   {
    //     Serial.println("Failed to read from DHT sensor!");
    //     return LogData{0, 0};
    //   }

    //   // Store the data values in a struct and return it
    //   LogData data = {h, t};
    //   return data;
    // }

// class LogData
// {
// public:
//   float temperatureCelsius;
//   float humidity;
//   // String timeStamp;

//   LogData(float h, float tC)
//   {
//     temperatureCelsius = tC;
//     humidity = h;
//     // timeStamp = ts;
//   }

//   void print()
//   {
//     Serial.println("Large Tent:    ");

//     Serial.print("- Temperature: ");
//     Serial.print(temperatureCelsius);
//     Serial.println("*C ");

//     Serial.print("- Humidity: ");
//     Serial.print(humidity);
//     Serial.println("%\t");

//     Serial.println("------------------------");
//   }
// };
