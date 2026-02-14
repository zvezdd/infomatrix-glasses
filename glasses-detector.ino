#include <Wire.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int motorPin = 9;   
const int distanceLimit = 200; 

void setup() {
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  Serial.begin(9600);

  if (!lox.begin()) {
    Serial.println("Error connect VL53L0X");
    while (1);
  }

  Serial.println("Датчик готов");
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) { 
    int distance = measure.RangeMilliMeter;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");

    if (distance < distanceLimit) {
      digitalWrite(motorPin, HIGH);  
    } else {
      digitalWrite(motorPin, LOW);   
    }

  } else {
    Serial.println("Нет данных");
    digitalWrite(motorPin, LOW);
  }

  delay(100);
}