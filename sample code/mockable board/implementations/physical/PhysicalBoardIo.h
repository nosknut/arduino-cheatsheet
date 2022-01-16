#include "interfaces/BoardIo.h"
#include "interfaces/SerialController.h"

class PhysicalBoardIo : public BoardIo
{
public:
    PhysicalBoardIo(SerialController serialController) : BoardIo(serialController)
    {
    }

    int analogRead(int pin) override
    {
        return analogRead(pin);
    }
    void analogWrite(int pin, int value) override
    {
        analogWrite(pin, value);
    }
    void pinMode(int pin, int mode) override
    {
        pinMode(pin, mode);
    }
    void digitalWrite(int pin, int value) override
    {
        digitalWrite(pin, value);
    }
    int digitalRead(int pin) override
    {
        return digitalRead(pin);
    }
    void delay(int ms) override
    {
        delay(ms);
    }
    void delayMicroseconds(int us) override
    {
        delayMicroseconds(us);
    }
    long millis() override
    {
        return millis();
    }
    long micros() override
    {
        return micros();
    }
};
