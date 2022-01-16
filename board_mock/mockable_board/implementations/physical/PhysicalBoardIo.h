#ifndef PhysicalBoardIo_h
#define PhysicalBoardIo_h

#include "Arduino.h"
#include "../../interfaces/BoardIo.h"
#include "../../interfaces/SerialController.h"

class PhysicalBoardIo : public BoardIo
{
public:
    PhysicalBoardIo(SerialController serialController);

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
