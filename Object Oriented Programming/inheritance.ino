#define USBCON
#include <Arduino.h>

/*
Almost every example with OOP so far has had a pin variable
and a setup() function that only sets the pinMode.
That was a lot of repetition. Let's be lazy and put that code in
a common place!
*/

/*
We can use the builtins but it is more understandable for someone that uses this code
to see the type "PinMode" instead of "uint8_t" (the dataType of INPUT and OUTPUT)
*/
enum class PinMode
{
    IN = INPUT,
    OUT = OUTPUT
};

class PinDevice
{
    /*
    protected members (variables or functions) are available in classes that
    extend the functionality of this class.
    That means "pin" will be available in the Motor and Thermometer class,
    but not for anyone using those classes. 
    */
protected:
    const int pin;

private:
    const PinMode mode;

public:
    PinDevice(const int pin, PinMode mode) : pin(pin), mode(mode)
    {
    }

    void setup()
    {
        pinMode(pin, (int)mode);
    }
};

/*
We must specify "public" before "PinDevice" so that anyone using
the thermometer also has access to the public functions and variables
inside PinDevice.
If we didn't specify "public", the compiler would give an error saying
"thermometer.setup() is inaccessible."
*/
class Thermometer : public PinDevice
{
public:
    Thermometer(const int pin) : PinDevice(pin, PinMode::INPUT)
    {
    }

    int getTemperature()
    {
        return analogRead(pin);
    }
};

class Motor : public PinDevice
{
public:
    Motor(const int pin) : PinDevice(pin, PinMode::OUTPUT)
    {
    }

    void start()
    {
        digitalWrite(pin, HIGH);
    }

    void stop()
    {
        digitalWrite(pin, LOW);
    }
};

////////////////////////////////////
// Main program would start here

Motor motor(2);
Thermometer thermometer(3);

void setup()
{
    /*
    Notice we have not defined a motor.setup()
    or thermometer.setup() method.
    setup() comes from the PinDevice class.
    motor.setup();

    We say that Motor and Thermometer "extend" PinDevice.
    */
    thermometer.setup();
}

void loop()
{
    if (thermometer.getTemperature() > 100)
    {
        motor.start();
    }
}

/*
This pattern is called "inheritance". Google it at your own peril.
It is very nice to know about and sometimes it is useful to know.
However, like OOP as a whole you should use it with care, and consider
simpler solutions before you use it.

An alternative to "inheritance" is "composition". In the file "dependency injection.ino"
we demonstrate this. In composition you take a class as a parameter, instead of extending it.
In this case, inheritance is better since having a PinDevice class inside a MotorClass would
not make anything simpler, compared to just having a pinNumber variable directly in the motorClass.

If you choose to use inheritance, take some time to reflect on the architecture (design) of your code
before you start. Otherwise you might be in for a headache!
*/
