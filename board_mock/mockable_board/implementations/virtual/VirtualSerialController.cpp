#include <iostream>
#include <string>
#include "VirtualSerialController.h"

void VirtualSerialController::print(const char str[])
{
    std::cout << str;
}

void VirtualSerialController::println(const char str[])
{
    print(str + 'n');
}

void VirtualSerialController::begin(int baudRate)
{
    println(("SerialController::begin(" + std::to_string(baudRate) + ")").c_str());
}

char *VirtualSerialController::readString()
{
    return (char *)std::cin.get();
}
