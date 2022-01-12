// READ THE FIRST 10 lines of comments in this file. You won't regret it!
// The following file contains most of the concepts you need to understand Arduino programming.

/*
The file has an extra large dose of comments to ensure everyone gets the help they need.
You will probably not need all that information, so try understanding by only reading the
code first, then resort to comments if something is confusing.

Remember, programming is about problem solving, not memorizing code.
You don't need to remember all this. You should save this file, and look
at it when you forget something (you definetly will forget something).
*/

// Are you confused or perhaps have some feedback? Ask me! knuton@ntnu.no

// Single line comment

/*
Multi line comment
*/

/*
We start with defining our global variables. A global variable is a variable that is not created inside a function or class,
and is as a result accessable from anywhere in the code. Try to define all your variables at the top to keep things organized.
*/

// Creates a variable named "motorPin" with the type of int (integer/whole number) and assigns it the value of 1.
int motorPin = 1;

/*
Creates a variable named "buttonPin" with the type of int and assigns it the value of 1.
This variable also is defined with the "const" keyword, which means it cannot be changed.
Try changing the value of this variable by writing "buttonPin = 3;" somewhere else in the code,
and see the error message that pops up.

Variables that you don't expect to change when your code is running should be declared with the "const" keyword.
You can always remove it later if you change your mind. The benefit of a "const"/immutable variable is that you
can look at it once and trust that the value never changes. (Makes the code easier to read)
*/
int const buttonPin = 2;

/*
The setup function is called once when the program starts.

It does something we call "black magic" where we don't know what it does,
but we know what do to with it. If you want to know more about the setup function and
why you should only configure io (inputs and outputs) in the setup function,
try to google it. Programming is very easy, but only if you know how to google your problems ;)
*/
void setup()
{
    // pinMode configures the physical pin to be an INPUT or OUTPUT
    // Motor pin OUTPUTs a signal to a motor and should be configured accordingly
    pinMode(motorPin, OUTPUT);
    // buttonPin takes an INPUT signal from a button and should be configured accordingly
    pinMode(buttonPin, INPUT);

    /*
    Serial.begin() is more "black magic" that starts serial communication.

     You can read more about the function here https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/
    */
    Serial.begin(9600);
}

/*
Defines a function named "pulseMotorSpeed" that takes a single argument of type "int" (integer/whole number) named "motor"
the argument/variable "motor" is used inside the function, and contains the pin number of the motor that should be pulsed.
pulseMotorSpeed has a return type of "void", meaning it returns nothing.
Check "bool buttonIsPressed()" for an example of a function that returns a value. 

Try to name your functions in a way that you know what they do from the name and athe arguments. (in this case "int motor")
*/
void pulseMotorSpeed(int motor)
{
    // digitalWrite(pinNumber, HIGH/LOW) sets the output pin to HIGH/on or LOW/off.
    digitalWrite(motor, HIGH); // Motor on
    /*
    delay(numberOfMilliseconds) stops the program for the specified number of milliseconds.
    this is useful when you want to make a delay between two actions. Note that when you run delay()
    the entire program stops, meaning if you have code to stop the motor if it hits something will not run
    until the delay is over.
    */
    delay(100);
    digitalWrite(motor, LOW); // Motor off
    delay(100);
    digitalWrite(motor, HIGH); // Motor on
    delay(100);
    digitalWrite(motor, LOW); // Motor off
    delay(100);
}

/*
    Defines a function named "buttonIsPressed" that takes no arguments.
    It has a return type of "bool" (boolean/true/false).
    You can see the return type of the function left of the function name.

    Notice how the function name is formulated as a quesrtion: buttonIsPressed?
    By naming functions like this we get code that looks like plain english.
    See how this function is used in "void loop()" for a demonstration.
*/
bool buttonIsPressed()
{
    // digitalRead(pinNumber) reads the value of the pin we connected a button to.
    // bool is a boolean data type. The possible values are
    // "true" (meaning "yes" or "1") and "false" (meaning "no" or "0").
    const bool buttonIsPressed = digitalRead(buttonPin);

    /*
    "return" is a keyword used in almost all programming languages
    it is followed by a value that will be "returned" to where the function was called from.
    The value returned from a function must have the same data type as the function's return type.
    The comment above this function describes what the return type is and where to find it.
    See "void loop()" to understand how this is used.
    */
    return buttonIsPressed;
}

/*
    The void loop() function runs over and over again, until the arduino is shut down.
    Put your main program code in the loop function.
*/
void loop()
{
    /*
    This is a while loop. The code inside the loop will run
    until the condition inside the () after while is false.
    In this case the condition is "buttonIsPressed()". Notice how
    we add the () after the function name. This means we are "calling"
    the fuction. That means we are running the code inside the function.
    "buttonIsPressed()" has a return type of "bool" (boolean/true/false).

    Funfact: We call the buttonIsPressed() function every time we run the loop,
    so that we get a fresh reading every time we run the loop. If we assigned the
    return value of buttonIsPressed() to a variable before the while() loop,
    the loop would never stop running unless we called buttonIsPressed() inside
    the loop and assigned the return value to the variable we used in the while loop.
    Because, remember, the it is only the code inside the loop ( between the {} ) that
    runs. Not the code above it, while the condition is true.
    */
    while (buttonIsPressed())
    {
        /*
        pulseMotorSpeed(motorPin) calls the function pulseMotorSpeed and
        passes it the value of motorPin as an argument.
        If you read the function code, the argument/variable "motor" will be
        assigned the value of motorPin.
        */
        pulseMotorSpeed(motorPin);
    }

    /*
    ! is an equality operator. It is equivalent to "not" in python.
    Because buttonIsPressed() returns a bool valuem can we use ! to invert it.
    This is the same as writing "if (buttonIsPressed() != true)"
    */
    if (!buttonIsPressed())
    {
        // delay(1000) pauses the program for 1000 milliseconds (1 second)
        delay(1000);
        /*
        Serial.println() prints a string to the serial monitor
        The serial monitor is a window on your pc that you can use to
        see the messages you send with this function.
        Useful if you want to see what your program is doing.
        See how to use the serial monitor here:
        https://youtu.be/umZZjoyRbdw?t=319
        */
        Serial.println("Button is not pressed");
        // Alternative way of printing this:
        Serial.print("Button");
        Serial.print(" ");
        Serial.print("is");
        Serial.print(" ");
        Serial.print("not");
        Serial.print(" ");
        /*
        Serial.print() does not add a new line to the serial monitor,
        meaning if you use Serial.print() you can fit many sensor values on a single line.
        Use Serial.println() on the last print to make a new line so that each loop gets its own line.
        This will read: "Button is not pressed"
        If you do not use println() below, the print will be:
        "Button is not pressedButton is not pressedButton is not pressedButton is not pressed" etc .... 
        */
        Serial.println("pressed");
    }
}
