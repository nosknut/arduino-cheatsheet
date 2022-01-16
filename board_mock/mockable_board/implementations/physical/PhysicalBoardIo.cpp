#include "Arduino.h"
#include "PhysicalBoardIo.h"
#include "interfaces/BoardIo.h"
#include "interfaces/SerialController.h"

PhysicalBoardIo::PhysicalBoardIo(SerialController serialController) : BoardIo(serialController)
{
}

int PhysicalBoardIo::analogRead(int pin)
{
    /*
        :: refrences global scope.
        This is needed because the function name is the same as the global arduino function called below.
        If we dont write ::analogRead instead of analogRead, this will be a recursive function that calls itself.
        */
    return ::analogRead(pin);
}

void PhysicalBoardIo::analogWrite(int pin, int value)
{
    ::analogWrite(pin, value);
}
void PhysicalBoardIo::pinMode(int pin, int mode)
{
    ::pinMode(pin, mode);
}

void PhysicalBoardIo::digitalWrite(int pin, int value)
{
    digitalWrite(pin, value);
    ::digitalWrite(pin, value);
}

int PhysicalBoardIo::digitalRead(int pin)
{
    return digitalRead(pin);
}

void PhysicalBoardIo::delay(int ms)
{
    ::delay(ms);
}

void PhysicalBoardIo::delayMicroseconds(int us)
{
    ::delayMicroseconds(us);
}

long PhysicalBoardIo::millis()
{
    return ::millis();
}

long PhysicalBoardIo::micros()
{
    return ::micros();
}
