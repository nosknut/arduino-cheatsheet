#ifndef VirtualSerialController_h
#define VirtualSerialController_h

#include <iostream>
#include <string>
#include "interfaces/SerialController.h"

class VirtualSerialController : public SerialController
{
public:
    void print(const char str[]);
    void println(const char str[]);
    void begin(int baudRate);
    char *readString();
};

#endif
