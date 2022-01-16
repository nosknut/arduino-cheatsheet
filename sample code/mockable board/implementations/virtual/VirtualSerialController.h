#include <iostream>
#include <string>
#include "interfaces/SerialController.h"

class VirtualSerialController : public SerialController
{
public:
    void print(const char str[]) override
    {
        std::cout << str;
    }
    void println(const char str[]) override
    {
        print(str + 'n');
    }
    void begin(int baudRate) override
    {
        println(("SerialController::begin(" + std::to_string(baudRate) + ")").c_str());
    }
    char *readString() override
    {
        return (char *)std::cin.get();
    }
};
