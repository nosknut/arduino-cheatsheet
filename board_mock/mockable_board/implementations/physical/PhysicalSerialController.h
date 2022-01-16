#ifndef PhysicalSerialController_h
#define PhysicalSerialController_h

#include "Arduino.h"
#include "interfaces/SerialController.h"

class PhysicalSerialController : public SerialController
{
public:
    void print(const char str[]);
    void println(const char str[]);
    void begin(int baudRate);
    char *readString();
};

#endif
