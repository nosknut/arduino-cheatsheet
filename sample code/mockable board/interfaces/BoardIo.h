#include "SerialController.h"

class BoardIo
{
public:
    SerialController serial;

    virtual int analogRead(int pin);
    virtual void analogWrite(int pin, int value);
    virtual void pinMode(int pin, int mode);
    virtual void digitalWrite(int pin, int value);
    virtual int digitalRead(int pin);
    virtual void delay(int ms);
    virtual void delayMicroseconds(int us);
    virtual long millis();
    virtual long micros();

    BoardIo(SerialController serialController) : serial(serialController)
    {
    }
};