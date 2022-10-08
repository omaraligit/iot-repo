#include <Arduino.h>
#include <ESP32Servo.h>

#define ONBOARD_LED 2
// create servo objects
Servo servo1;



void runServo(void *parameter)
{
    Serial.print("Task is running on: ");
    Serial.println(xPortGetCoreID());
    for (;;)
    {
        servo1.write(0);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        servo1.write(45);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        servo1.write(90);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        servo1.write(135);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        servo1.write(170);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void toggleLED(void *parameter)
{
    for (;;)
    {
        // infinite loop
        // Turn the LED on
        digitalWrite(ONBOARD_LED, HIGH);
        // Pause the task for 500ms
        vTaskDelay(80 / portTICK_PERIOD_MS);
        // Turn the LED off
        digitalWrite(ONBOARD_LED, LOW);
        // Pause the task again for 500ms
        vTaskDelay(80 / portTICK_PERIOD_MS);
    }
}


void setup()
{
    pinMode(ONBOARD_LED, OUTPUT);
    servo1.attach(18);
    Serial.begin(921600);

    xTaskCreate(toggleLED, "Toggle LED", 1000, NULL, 2, NULL);
    xTaskCreate(runServo, "Servo Steper", 1000, NULL, 1, NULL);
}

void loop()
{

}
