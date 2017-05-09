
/*
 * 
 * Example using ESP8266 
 * by Jon Simmons  5/9/17
 * tested on ESP8266-01
 * 
 */

#include <Bme280BoschWrapper.h>

#define I2C_SCL 0  //scl on GPIO0
#define I2C_SDA 2  //sda on GPIO2

Bme280BoschWrapper bme280(true);

void setup() {
  Serial.begin(9600);
  Serial.println("BME280 Bosch test");
  delay(1000);

  while(!bme280.beginI2C(0x76,I2C_SDA,I2C_SCL ))
  {
    Serial.println("Cannot find sensor.");
    delay(1000);
  }
}

void loop() {
  bool ok = bme280.measure();

  if(ok)
  {
    Serial.print("Temperature: ");
    Serial.print(bme280.getTemperature() / 100.0);
    Serial.println(" [C]");
    Serial.print("Humidity: ");
    Serial.print(bme280.getHumidity() / 1024.0);
    Serial.println(" [%]");
    Serial.print("Pressure: ");
    Serial.print(bme280.getPressure());
    Serial.println(" [Pa]");
    
//extra precision values
    Serial.print("Temperature double: ");
    Serial.print(bme280.getTemperatureDouble());
    Serial.println(" [C]");
    Serial.print("Humidity double: ");
    Serial.print(bme280.getHumidityDouble());
    Serial.println(" [%]");
    Serial.print("Pressure double: ");
    Serial.print(bme280.getPressureDouble());
    Serial.println(" [Pa]");

    Serial.print("Pressure precise: ");
    Serial.print(bme280.getPressurePrec() / 256.0);
    Serial.println(" [Pa]");

    Serial.println();
  }
  else
  {
    Serial.println("Measuring failed.");
  }
  
  delay(5000);
}
