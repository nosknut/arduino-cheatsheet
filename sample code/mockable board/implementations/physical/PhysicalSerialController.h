#include "interfaces/SerialController.h"

class PhysicalSerialController : public SerialController
{
public:
    void print(const char str[]) override
    {
        Serial.print(str);
    }
    void println(const char str[]) override
    {
        Serial.println(str);
    }
    void begin(int baudRate) override
    {
        Serial.begin(baudRate);
    }
    char *readString() override
    {
        return Serial.readString();
    }
};
