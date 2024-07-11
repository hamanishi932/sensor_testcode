#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <SPI.h>

Adafruit_BME280 bme_1;
float temp_1;
float pressure_1;
float humid_1;

void setup() {
  Serial.begin(115200);
  bool status;
  status = bme_1.begin(0x76);
  while (!status) {
     Serial.println("BME280 sensorが使えません");
     delay(1000);
  }
  Serial.print("Setup complete");
}

void loop() {
      temp_1=bme_1.readTemperature();
      pressure_1=bme_1.readPressure() / 100.0;
      humid_1=bme_1.readHumidity();
      Serial.print("温度 ;");
      Serial.print(temp_1);
      Serial.println(" °C");
       
      Serial.print("気圧 ;");
      Serial.print(pressure_1);
      Serial.println(" hPa");
      Serial.print("湿度 ;");
      Serial.print(humid_1);
      Serial.println(" %");
      Serial.println();
      delay(1000);
}
