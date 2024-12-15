#include <Wire.h>
#include <Adafruit_INA219.h>

// Number of sensors
int numSensors = 2;

// Initialising sensor instances
Adafruit_INA219 sensor0(0x40);
Adafruit_INA219 sensor1(0x41);

Adafruit_INA219 sensors [2] = {sensor0, sensor1};

int obsNum = 0;
unsigned long time = 0, prevTime = 0;

void setup() {
  // Note the required baud rate
  Serial.begin(115200);

  // (IMPORTANT!) Initialise and set to highest precision possible (0.1mA resolution)
  for (int i=0; i<numSensors; i++) {
    (sensors[i]).begin();
    (sensors[i]).setCalibration_16V_400mA();
  }

  // Printing column headers
  Serial.print("S. No.");
  Serial.print(", ");
  Serial.print("Time (s)");
  Serial.print(", ");

  for (int i=0; i<numSensors; i++) {
    // Measuring 4 parameters per sensor
    for (int j=0; j<4; j++) {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.print(", ");
    }
    // Empty column to indicate end of this sensor's data
    Serial.print(" ");
    Serial.print(", ");
  }
  Serial.println();

  // 2-column offset due to S.No. and Time columns
  Serial.print(", ");
  Serial.print(", ");
  for (int i=0; i<numSensors; i++) {
    Serial.print("Current (mA)");
    Serial.print(", ");
    Serial.print("Bus Voltage (mV)");
    Serial.print(", ");
    Serial.print("Shunt Voltage (mV)");
    Serial.print(", ");
    Serial.print("Power (mW)");
    Serial.print(", ");
    // Empty column to indicate end of this sensor's data
    Serial.print(" ");
    Serial.print(", ");
  }
  Serial.println();
}

void loop() {
  obsNum++;
  time = (millis() - prevTime);
  prevTime = millis();

  Serial.print(obsNum);
  Serial.print(", ");
  Serial.print(time);
  Serial.print(", ");

  // Iterating sensor-wise
  for (int i=0; i<numSensors; i++) {

    Serial.print((sensors[i]).getCurrent_mA());
    Serial.print(", ");
    Serial.print((sensors[i]).getBusVoltage_V() * 1000);
    Serial.print(", ");
    Serial.print((sensors[i]).getShuntVoltage_mV());
    Serial.print(", ");
    Serial.print((sensors[i]).getPower_mW());
    Serial.print(", ");
    // Empty column to indicate end of this sensor's data
    Serial.print(" ");
    Serial.print(", ");

  }

  Serial.println();
  delay(2000);
}
