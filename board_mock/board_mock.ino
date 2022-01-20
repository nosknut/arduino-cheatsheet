// Comment the next 3 lines to disable Viritualize
#define USBCON
#include <Arduino.h>
#include <Viritualize.h>

// Code below works normaly
void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(12, INPUT);
}

void loop()
{
    Serial.println("looping ...");
    if (digitalRead(12))
    {
        delay(1000);
    }
    digitalWrite(13, HIGH);
    analogWrite(13, 255);
}
