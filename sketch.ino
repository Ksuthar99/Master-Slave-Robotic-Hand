
#include <ESP32Servo.h>

Servo fingers[5];

int sensors[5] = {34, 35, 32, 33, 25};
int motors[5] = {13, 14, 12, 15, 16};

int value;
int angle;

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 5; i++) {
    fingers[i].attach(motors[i]);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    value = analogRead(sensors[i]);

    angle = map(value, 0, 4095, 0, 180);

    fingers[i].write(angle);
  }

  delay(20);
}