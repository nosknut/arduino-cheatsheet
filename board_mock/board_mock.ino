#pragma once

#include "mockable_board/MockableBoard.h"

#define debug 1

void main()
{
    setup();
    loop();
}

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
