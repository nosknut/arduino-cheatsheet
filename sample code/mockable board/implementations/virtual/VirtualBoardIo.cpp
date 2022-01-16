#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "VirtualBoardIo.h"
#include "interfaces/BoardIo.h"
#include "interfaces/SerialController.h"

VirtualBoardIo::VirtualBoardIo(SerialController serialController) : BoardIo(serialController)
{
}

int VirtualBoardIo::analogRead(int pin)
{
    return (int)serial.readString();
}

void VirtualBoardIo::analogWrite(int pin, int value)
{
    serial.println(("{\"pin\": " + std::to_string(pin) + ", \"value\": " + std::to_string(value) + "}").c_str());
}

void VirtualBoardIo::pinMode(int pin, int mode)
{
    serial.println(("{\"pin\": " + std::to_string(pin) + ", \"mode\": " + std::to_string(mode) + "}").c_str());
}

void VirtualBoardIo::digitalWrite(int pin, int value)
{
    serial.println(("{\"pin\": " + std::to_string(pin) + ", \"value\": " + std::to_string(value) + "}").c_str());
}

int VirtualBoardIo::digitalRead(int pin)
{
    return (int)serial.readString();
}

void VirtualBoardIo::delay(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void VirtualBoardIo::delayMicroseconds(int us)
{
    std::this_thread::sleep_for(std::chrono::microseconds(us));
}

long VirtualBoardIo::millis()
{
    return millis();
}

long VirtualBoardIo::micros()
{
    return micros();
}
