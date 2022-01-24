#define USBCON
#include <Arduino.h>
#include "Motor.ino"

// The "Motor.ino" file is automatically included. In arduino projects,
// all .ino files in the folder are automatically imported.

// Read the "Motor.ino" file to see what the functions in motor1 and motor2 does.
/*
    Here we instantiate (create a unique version of) two motor objects.
    When we write "Motor motor1(3);" we call the constructor in the Motor class,
    and that creates a new instance of the Motor class, where in the case of motor1 the "pin" variable
    inside the class instance is given a value of 3. motor2 is a different instance of the Motor class,
    where the "pin" variable inside the class instance is given a value of 5. By looking at the code in
    Motor.ino, we see that the "Motor" class has a constructor that takes a single parameter, which is the "pin"
    variable. We see that the "pin" variable is used when we call functions to setup() and update() the motor.
*/
Motor motor1(3);
Motor motor2(5);
const int buttonPin = 2;

void setup()
{
    // By reading the setup() function inside Motor.ino we see that the motor1.setup() and motor2.setup() function
    // sets the pinMode() for the motor pins to OUTPUT.
    motor1.setup();
    motor2.setup();

    pinMode(buttonPin, INPUT);
}

void loop()
{
    const bool buttonPressed = digitalRead(buttonPin);

    // In this if-statement we run motor1 if the button is pressed, and motor2 if the button is not pressed.
    if (buttonPressed)
    {
        motor1.setSpeed(255);
        motor2.setSpeed(0);
    }
    else
    {
        motor1.setSpeed(0);
        motor2.setSpeed(255);
    }

    /*
        By reading setSpeed() function inside Motor.ino we see that setSpeed() does not actually change the speed of the motor.
        It simply changes the internal speed variable.
        The update() function inside the Motor class however, sets the speed of the motor to the value of the internal speed variable
        with "analogWrite(pin, speed);".
        That means we must call motor1.update() and motor2.update() at the end of the void loop() to actually see the speed change.
        This seems impractical, and in this case it would be moreeffective to have the setSpeed() function also call update() so we immedietly
        see the speed change without extra work. We will however often see situations where this is not the case, and the current solution
        is better. Choosing between the two is up to you. Happy problem solving!
    */
    motor1.update();
    motor2.update();
}