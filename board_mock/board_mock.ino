#include <Arduino.h>
#include <MockableBoard.h>

#define debug 0
BoardIo board = getBoard();

void setup()
{
    board.digitalRead(0);
    board.serial.begin(9600);
    board.pinMode(13, OUTPUT);
    board.pinMode(12, INPUT);

    Serial.println("Hello World!");

    digitalWrite(A0, 255);
}

void loop()
{
    board.serial.println("looping ...");
    board.digitalRead(12);
    board.delay(1000);
    board.digitalWrite(13, HIGH);
}
