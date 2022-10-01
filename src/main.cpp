#include <ESP32Servo.h>
// create servo objects 
Servo servo1;
void setup()
{
    servo1.attach(18);
}

void loop()
{
    servo1.write(0);
    delay(2000);
    servo1.write(45);
    delay(2000);
    servo1.write(90);
    delay(2000);
    servo1.write(135);
    delay(2000);
    servo1.write(170);
    delay(2000);
}