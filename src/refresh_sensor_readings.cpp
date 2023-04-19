#include <refresh_sensor_readings.h>

DHT dht(DATA_INPUT_PIN, DHTTYPE);

void refreshReadings() {
  delay(8000);
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int ldrValue = analogRead(LDR_PIN);
    float light = (ldrValue / 1023.0) * 100.0;

    if (isnan(temperature) || isnan(humidity))
    {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print(light);
    Serial.println(" %");
}