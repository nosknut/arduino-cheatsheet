#include "Arduino.h"

// Serial mock
void Serial::print(const char str[]);
void Serial::println(const char str[]);
void Serial::begin(int baudRate);
char *Serial::readString();

// Board mock
int analogRead(uint8_t pin);
void analogWrite(uint8_t pin, uint8_t value);
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
int digitalRead(uint8_t pin);
void delay(unsigned long ms);
void delayMicroseconds(unsigned long us);
long millis();
long micros();
