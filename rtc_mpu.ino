#include <Wire.h>
#include "RTClib.h"
#include <MPU6050_tockn.h>

#define I2C_SDA 17
#define I2C_SCL 16

TwoWire I2CMPU = TwoWire(0);

MPU6050 mpu6050(I2CMPU);

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(115200);
  Wire.begin();
  I2CMPU.begin(I2C_SDA, I2C_SCL, 100000);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  // put your setup code here, to run once:
    if (! rtc.begin()) {
      Serial.println("Couldn't find RTC");
      while (1);
    }
    rtc.adjust(DateTime(__DATE__, __TIME__));
//    rtc.adjust(DateTime(2022,11,2,12,1 9,00));
}

void loop() {
  // put your main code here, to run repeatedly:
//  DateTime now = rtc.now();
//  Serial.println(String(daysOfTheWeek[now.dayOfTheWeek()]) + "," + String(now.hour(), DEC) + ":" + String(now.minute(), DEC) + ":" + String(now.second(), DEC));
//  delay(100);
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

}
