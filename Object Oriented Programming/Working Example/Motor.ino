#define USBCON
#include <Arduino.h>

// NB! Comments in this file refer to the code line directly below the comment.

/*
This is a class definition
It is a template for how to create a class called "Motor"
Classes are objects that contain data and functions.
They are a nice way to organize your functions in groups,
as well as keeping your variables in one place close to the code that
uses them (this is easier to read and understand).
We most often use classes to keep track of "state", which is a common
term for variables that keep track of information that we cannot simply
read directly from a sensor on demand. An example of state is the direction
we want the motor to run, the speed we want it to run at, or the time since
we started the motor.

Imagine having a project with 100 motors. Now imagine all of those motors
having temperature sensors to protect from overheating, switches to make sure
they dont run too long and break something and an internal state to keep track
of how fast every motor is running.
(useful if you are doing some math to calculate how fast a motor is running in realtime).

That is at least 4 different variables per motor. And that is just safety and basic math!
Do you want all those variables and all that code mixed in with other code?
With a class you can put all that in one place, create 100 instances of the "Motor" class,
and give each of those instances the io pins where the motor and its related sensors are connected.
Suddenly, your code looks a lot cleaner!
*/
class Motor
{
    // Private fields (variables) and functions can only be accessed inside this class definition
private:
    /*
        We declare (create and define the name and type of) the "pin" variable.
        The "const" keyword means that the variable can't be changed once it
        has been initialized (been assigned a value for the first time).
        Ofe of the reason for making a variable "const"/"immutable" is that
        you can read the code once, and trust that the value never changes.
        It can save hours of headache in larger programs
        (funfact: there is no such thing as a small programming project)
    */
    int const pin;
    /*
        We declare (create and define the name and type of) and
        initialize (assign a value to for the first time) the "speed" variable.
        It has a type of integer and can be assigned a new value at any time.
    */
    int speed = 0;

    // Public fields and functions can be accessed from outside this class definition
public:
    /*
        This is the "Constructor" for the class.
        
        This is the function we call when we create a new motor object.
        In this case, different instances of the motor class will be created for each motor,
        where the difference between them is the "pin" variable we pass to the constructor when we call it
        the ": pin(pin)" part after this function is where we give the "int const pin;" variable at the top of this class a value.
        When an object is created from this class with the following code: Motor motor(3); the "int const pin" variable will be set to 3. 
    */
    Motor(int motorPin) : pin(motorPin)
    {
        // Code you put here will run once when an instance of the motor class is created.
    }

    /*
    This is not the "void setup()" function you know from before.
    This is simply a function that we choose to call setup because it is convenient.
    The two are completely separate and have nothing to do with eachother.
    We want to call this function manually inside "void setup()" in our main program.
    The reason we have defined this function is that now, anyone who wants to use this code does not have to 
    know how to set up the motor. They only need to call this function, and our logic is neatly encapsulated here.
*/
    void setup()
    {
        pinMode(pin, OUTPUT);
    }

    /*
    This function does exactly what its name suggests.
    Why can we not simply make the speed variable public?
    We can, but generally it is better to make a function for setting properties.
    It will be easier in the future if we want to add safeguards to ensure we don't
    pass too much power to the motor and make it burn up, or to keep a robot
    arm within a safe zone (more practical if this was a "void setPosition(x, y)" function).
    */
    void setSpeed(int speed)
    {
        /*
        "this" refers to the instance of this class. The code in this file defines a recipe
        for how to create a motor object, and how to work with it once it is created.
        You can create separate instance of this class, the "this" keyword refers to that instance.
        In the line below we are accessing the "speed" variable for "this" instance of the class
        using the -> accessor. This is similar to writing this["speed"] = speed; in python,
        where "this" is a dictionary and "speed" is a key. 
        the -> operator differs from the . operator, in that the -> operator is used to access
        members of a pointer, and the . operator is used to access members of a class.
        
        Generally:
        When the left side of the accessor is "this", use ->
        When the left side of the accessor is not "this", use .        
        */
        this->speed = speed;
    }

    /*
    Again we see a non-magical function. It is a normal function and nothing more.
    For this code to run, we must call the function manually on our own.
    We call it update because we are updating the motor with the speed we 
    have set somewhere else in the code using setSpeed(200);
    The reason we might want to do it this way is because often times we
    need to keep track of something, like the position of a motor, the time it
    has been active, maybe temperature of the motor to shut it down if it overheats etc. We can
    do all that in this function, and not need the person using this code to know how it works.
    This also reduces the chance that someone will forget to update any safeguards, and
    potentially cause damage to the motor or something else.
    */
    void update()
    {
        analogWrite(pin, speed);
    }
};
