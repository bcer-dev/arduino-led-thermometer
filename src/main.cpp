#include <Arduino.h>

#define SENSOR_PIN      A0
#define BLUE_LED_PIN    4
#define GREEN_LED_PIN   3
#define RED_LED_PIN     2

void temperature_handler(double voltage);

void setup()
{
    Serial.begin(9600);
    pinMode(SENSOR_PIN, INPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop()
{
    auto sensor_value = analogRead(SENSOR_PIN);
    auto voltage = sensor_value / 1024.0 * 5.0;
    temperature_handler(voltage);
}

void temperature_handler(double voltage)
{
    auto temperature = (voltage - 0.5) * 100;

    if (temperature < 20)
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);
    }
    else if (temperature > 25)
    {
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
    }
    else
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, LOW);
    }
}