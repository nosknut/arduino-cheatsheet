#ifndef VirtualBoardIo_h
#define VirtualBoardIo_h

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "../../interfaces/BoardIo.h"
#include "../../interfaces/SerialController.h"

class VirtualBoardIo : public BoardIo
{
public:
    VirtualBoardIo(SerialController serialController);

    int analogRead(int pin);
    void analogWrite(int pin, int value);
    void pinMode(int pin, int mode);
    void digitalWrite(int pin, int value);
    int digitalRead(int pin);
    void delay(int ms);
    void delayMicroseconds(int us);
    long millis();
    long micros();
};

#endif
