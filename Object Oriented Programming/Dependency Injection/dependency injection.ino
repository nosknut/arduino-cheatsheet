/*
Funfact:
Did you know that if you take a wild guess on what something does in programming,
there is a good chance you are right? This code may look different, but if you
look at commonalities such as names, as well as how the code is used, you might just
figure it out without reading about it for hours ;)
*/

/*
Thermometer class to keep track of the pin, setup and
possibly average temperature.
*/
class Thermometer
{
    // We don't allow access to the thermometer pin outside this class
private:
    const int pin;

public:
    Thermometer(const int pin) : pin(pin)
    {
    }

    int getTemperature()
    {
        return analogRead(pin);
    }

    void setup()
    {
        pinMode(pin, INPUT);
    }
};

/*
    A class to encapsulate the pin, setup and flashing logic.
*/
class WarningLamp
{
private:
    const int pin;

public:
    WarningLamp(const int pin) : pin(pin)
    {
    }

    void turnOn()
    {
        digitalWrite(pin, HIGH);
    }

    void turnOff()
    {
        digitalWrite(pin, LOW);
    }

    /*
    This should be upgraded to use an alternative solution to delay,
    so that it does not pause the rest of the program for 2000ms.
    Perhaps make a StopWatch class that keeps track of the time
    that has passed since the lamp was turned on/off?
    */
    void flash()
    {
        turnOn();
        delay(1000);
        turnOff();
        delay(1000);
    }

    void setup()
    {
        pinMode(pin, OUTPUT);
    }
};

// Motor class to encapsulate the overheating shutdown and flash warningLamp logic
class Motor
{
private:
    const int pin;
    Thermometer thermometer;
    WarningLamp warningLamp;

public:
    //Constructor for the motor class
    Motor(
        const int motorPin,
        const Thermometer thermometerInstance,
        WarningLamp warningLampInstance
        // Initialize the private variables that were declared at the top of the class
        // The pattern is: classVariable(constructorParameter)
        ) : pin(motorPin),
            thermometer(thermometerInstance),
            warningLamp(warningLampInstance)
    {
        // Constructor code
    }

    bool isOverheating()
    {
        return thermometer.getTemperature() > 1000;
    }

    void start()
    {
        digitalWrite(pin, HIGH);
    }

    void stop()
    {
        digitalWrite(pin, LOW);
    }

    void update()
    {
        if (isOverheating())
        {
            stop();
            warningLamp.flash();
        }
    }

    void setup()
    {
        pinMode(pin, OUTPUT);
        thermometer.setup();
        warningLamp.setup();
    }
};

class Button
{
private:
    const int pin;

public:
    Button(const int pin) : pin(pin)
    {
    }

    bool isPressed()
    {
        return digitalRead(pin);
    }

    void setup()
    {
        pinMode(pin, INPUT);
    }
};

///////////////////////////////////////////////////////
// The above code can be in different files.
// The main program starts here.

/*
Dependency injection means shuving one class into the constructor of another class.
In this case we inject a thermometer and a warning lamp into a motor.
We could also simply take the thermometer pin as an argument to the motor, instead of injecting the
whole thermometer, however imagine how complicated these constructors would get.
Besides, now it is clear to who ever reads this code where the pins are used.
We can clearly see that the pin A0 (analog port 0) is used in the thermometer for motor 1.

Also take note that each motor has its own thermometer, but there is only one warning lamp.
We inject the same warning lamp that is connected to pin 9 into all the motors.
That means they all use the same lamp, but if we wanted to use a different lamp for one or
more of the motors, we can do that as well, the same way de did the thermometers.

Observation:
The motor.setup() function calls the warningLamp.setup() function.
In our case this is fine, but if the warningLamp.setup() function for some reason should only be
called once, we would have to change this code a little.
Pay attention to such pitfalls when writing your code.
*/

WarningLamp warningLamp(9);

Motor motor1(1, Thermometer(A0), warningLamp);
Motor motor2(2, Thermometer(A1), warningLamp);
Motor motor3(3, Thermometer(A2), warningLamp);
Motor motor4(4, Thermometer(A3), warningLamp);

Button button = Button(5);

void setup()
{
    motor1.setup();
    motor2.setup();
    motor3.setup();
    motor4.setup();

    button.setup();
}

/*
You might wonder:
Why should i do something like this?
Storing the pin in a variable and using digitalWrite and pinMode directly
is simpler.

In many cases you would be correct!
In fact, Object Oriented Programming is often not the best place to start, and if this was
the entire program, you would probably be better off writing a couple of functions.
If there is a simpler solution, you should use it.
That being said, you should take a moment to consider the pros and cons of both.
OOP gives you a more consise looking code.
motor.start();
is a little easier to read than
digitalWrite(motorPin, HIGH);
when your code starts passing the 1000 lines mark.
Not to mention if you have a bunch of sensors in your system, things can start looking
very messy when you have to keep track of everything.

Do not overengineer, but make sure you don't underestimate the complexity of your problem either.
*/
void loop()
{
    if (button.isPressed())
    {
        motor1.start();
        motor2.start();
        motor3.start();
        motor4.start();
    }

    motor1.update();
    motor2.update();
    motor3.update();
    motor4.update();
}
