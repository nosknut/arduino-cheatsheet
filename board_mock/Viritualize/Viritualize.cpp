#define USBCON
#include "Arduino.h"

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

// Serial mock
void Serial::print(const char str[])
{
    std::cout << str;
}

void Serial::println(const char str[])
{
    print(str + 'n');
}

void Serial::begin(uint8_t baudRate)
{
    println(("Serial.begin(" + std::to_string(baudRate) + ")").c_str());
}

char *Serial::readString()
{
    return (char *)std::cin.get();
}

// Board mock
int analogRead(uint8_t pin)
{
    return (uint8_t)serial.readString();
}

void analogWrite(uint8_t pin, uint8_t value)
{
    serial.println(("{\"pin\": " + std::to_string(pin) + ", \"value\": " + std::to_string(value) + "}").c_str());
}

void pinMode(uint8_t pin, uint8_t mode)
{
    serial.println(("{\"pin\": " + std::to_string(pin) + ", \"mode\": " + std::to_string(mode) + "}").c_str());
}

void digitalWrite(uint8_t pin, uint8_t value)
{
    serial.println(("{\"pin\": " + std::to_string(pin) + ", \"value\": " + std::to_string(value) + "}").c_str());
}

int digitalRead(uint8_t pin)
{
    return (uint8_t)serial.readString();
}

void delay(unsigned long ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void delayMicroseconds(unsigned long us)
{
    std::this_thread::sleep_for(std::chrono::microseconds(us));
}

unsigned long millis()
{
    return millis();
}

unsigned long micros()
{
    return micros();
}
