#pragma once

#include "Arduino.h"
#include "mockable_board/interfaces/BoardIo.h"
#include "mockable_board/interfaces/SerialController.h"

#ifndef debug
#define debug 0
#endif

#if (debug)
#include "mockable_board/implementations/virtual/VirtualBoardIo.h"
#include "mockable_board/implementations/virtual/VirtualSerialController.h"
BoardIo board = VirtualBoardIo(VirtualSerialController());
#else
#include "mockable_board/implementations/physical/PhysicalBoardIo.h"
#include "mockable_board/implementations/physical/PhysicalSerialController.h"
BoardIo board = PhysicalBoardIo(PhysicalSerialController());
#endif // if(debug)

#define debug 0

void setup()
{
    board.serial.begin(9600);
    board.pinMode(13, OUTPUT);
    board.pinMode(12, INPUT);

    Serial.println("sadghjk");

    digitalWrite(A0, 255);
}

void loop()
{
    board.serial.println("1");
    board.digitalRead(12);
    board.delay(1000);
    board.digitalWrite(13, HIGH);
}
