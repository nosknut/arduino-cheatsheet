#include "Arduino.h"
#include "PhysicalSerialController.h"
#include "interfaces/SerialController.h"

void PhysicalSerialController::print(const char str[])
{
    Serial.print(str);
}

void PhysicalSerialController::println(const char str[])
{
    Serial.println(str);
}

void PhysicalSerialController::begin(int baudRate)
{
    Serial.begin(baudRate);
}

char *PhysicalSerialController::readString()
{
    return Serial.readString();
}
