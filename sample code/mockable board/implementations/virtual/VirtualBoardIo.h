#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "interfaces/BoardIo.h"
#include "interfaces/SerialController.h"

class VirtualBoardIo : public BoardIo
{
public:
    VirtualBoardIo(SerialController serialController) : BoardIo(serialController)
    {
    }

    int analogRead(int pin) override
    {

        return (int)serial.readString();
    }
    void analogWrite(int pin, int value) override
    {
        serial.println(("{\"pin\": " + std::to_string(pin) + ", \"value\": " + std::to_string(value) + "}").c_str());
    }
    void pinMode(int pin, int mode) override
    {
        serial.println(("{\"pin\": " + std::to_string(pin) + ", \"mode\": " + std::to_string(mode) + "}").c_str());
    }
    void digitalWrite(int pin, int value) override
    {
        serial.println(("{\"pin\": " + std::to_string(pin) + ", \"value\": " + std::to_string(value) + "}").c_str());
    }
    int digitalRead(int pin) override
    {
        return (int)serial.readString();
    }
    void delay(int ms) override
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
    void delayMicroseconds(int us) override
    {
        std::this_thread::sleep_for(std::chrono::microseconds(us));
    }
    long millis() override
    {
        return millis();
    }
    int micros() override
    {
        return micros();
    }
};
