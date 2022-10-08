#include <Arduino.h>

void setup()
{
    Serial.begin(921600);
    pinMode(23,INPUT);
    pinMode(2,OUTPUT);
}

void loop()
{
    Serial.println(analogRead(GPIO_NUM_15));
    analogWrite(2,analogRead(GPIO_NUM_15)*(3.3/4095));
    delay(100);
}