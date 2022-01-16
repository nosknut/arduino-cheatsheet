#ifndef BoardIo_h
#define BoardIo_h

#include "SerialController.h"

class BoardIo
{
public:
    SerialController serial;

    int analogRead(int pin);
    void analogWrite(int pin, int value);
    void pinMode(int pin, int mode);
    void digitalWrite(int pin, int value);
    int digitalRead(int pin);
    void delay(int ms);
    void delayMicroseconds(int us);
    long millis();
    long micros();
    BoardIo(SerialController serialController);
};

#endif
