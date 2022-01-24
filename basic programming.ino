#define USBCON
#include <Arduino.h>

void loop()
{
    // Data types:
    // https://www.javatpoint.com/arduino-data-types
    // Sizes:
    // https://robotresearchlab.com/2016/11/14/variable-data-types/
    int smallNumber = 0;
    long largeNumber = 0;
    double veryLargeNumber = 0.0;
    float decimalNumber = 0.0;
    bool booleanValue = false;
    char character = 'a';
    String text = "Hello World";

    // Creating a boolean variable
    bool buttonPressed = true;
    // Inverting a boolean value with !
    bool buttonNotPressed = !buttonPressed;
    // Creating an integer variable
    int sensorValue = 500;
    // Comparing values more than
    bool sensorIsOverflowing = sensorValue > 700;
    // Comparing values less than
    bool sensorIsTooLow = sensorValue < 300;

    // More comparisons
    if (sensorValue > 100)
    {
        // sensorValue is more than 100
    }
    if (sensorValue < 100)
    {
        // sensorValue is less than 100
    }
    if (sensorValue >= 100)
    {
        // sensorValue is more than or equal to 100
    }
    if (sensorValue <= 100)
    {
        // sensorValue is less than or equal to 100
    }
    if (sensorValue == 100)
    {
        // sensorValue is equal to 100
    }
    if (sensorValue != 100)
    {
        // sensorValue is not equal to 100
    }

    // Incrementing a variable
    int counter = 0;
    // Add 1 to counter
    counter++;
    // Remove 1 from counter
    counter--;
    counter += 1;
    counter -= 1;
    //Add 2 to counter
    counter += 2;
    counter -= 2;

    // If statements
    bool condition = true;
    bool condition2 = false;

    if (condition)
    {
        // Do something
    }

    if (condition)
    {
        // Do something
    }
    else
    {
        // Do something else
    }

    if (condition)
    {
        // Will run if condition is true
        // Will not run if condition is false
    }
    else if (condition2)
    {
        // Will run if condition is false and condition2 is true
        // You can add more else if() statements before else {} if you need it.
    }
    else
    {
        // Do something else if both condition and condition2 are false
        // Will not run if condition or condition2 is true
    }

    enum class TerminalCommand
    {
        START = 'a',
        STOP = 'b',
        LEFT = 'c',
        RIGHT = 'd',
    };

    char commandFromTerminal = 'a';

    /*
    By writing "(Type)variable" instead of just writing "variable" we are "casting" the variable to the type.
    A "char" type is actually stored as an "int", and the TerminalCommand enum values ('a', 'b', c' etc...) are
    cast to int when we create the enum. So the true value of TerminalCommand::START is actually 97,
    which is the int representation of the char 'a'.
    */
    switch ((TerminalCommand)commandFromTerminal)
    {
    case TerminalCommand::START: // Start
        /* code placed here will run for the current value of commandFromTerminal */
        break;

    case TerminalCommand::STOP: // Stop
        /* this code will only run if (commandFromTerminal == 'b') */
        break;

    case TerminalCommand::LEFT: // Left
        /* this code will only run if (commandFromTerminal == 'c') */
        break;

    case TerminalCommand::RIGHT: // Right
        /* this code will only run if (commandFromTerminal == 'd') */
        break;

    default:
        /* this code will only run if none of the cases above match the variable "commandFromTerminal" */
        break;
    }

    // For loops
    /*
    The following describes what each entry
    (separated with ;) does in order:
    int i = 0; // Initialize the variable i with the value 0
    i < 10; // Check if i is less than 10
    i++; // Increments (increases the value of) i by 1

    int i = 0; is only run once.

    i < 10; is run every time the loop runs, until i is less than 10.
    If i is less than 10, the loop will stop running.

    i++ will, same as "i < 10;", run every time the loop runs, until i is less than 10. 
    */
    for (int i = 0; i < 10; i++)
    {
        // Do something each time the loop runs
        Serial.println(i); // Will print 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 in the monitor
    }

    // For loop with decreasing value
    for (int i = 10; i > 0; i--)
    {
        // Do something each time the loop runs
        Serial.println(i); // Will print 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 in the monitor
    }

    // Waiting for serial input
    void waitForStartCommand()
    {
        while (true)
        {
            if (Serial.available() > 0)
            {
                String command = Serial.readString();
                if (command == "start")
                {
                    break;
                }
            }
        }
    }
    waitForStartCommand();
    // Run code after start command is received

    // IO functions:
    int buttonPin = 1;
    int motorPin = 2;
    int thermometerPin = 3;
    int electricalHeaterPin = 4;

    pinMode(buttonPin, INPUT);
    pinMode(motorPin, OUTPUT);
    pinMode(thermometerPin, INPUT);
    pinMode(electricalHeaterPin, OUTPUT);

    bool buttonIsPressed = digitalRead(buttonPin); // Returns 0 or 1
    digitalWrite(motorPin, HIGH);                  // Sets the motorPin to HIGH

    int temperature = analogRead(thermometerPin); // Returns a value between 0 and 1023
    analogWrite(electricalHeaterPin, 255);        // Sets the electricalHeaterPin to 255 (0%=0, 100%=255)

    // Serial monitor
    Serial.begin(9600);
    Serial.print("The temperature is: ");
    temperature = 1023;
    Serial.println(temperature);
    // Prints:  "The temperature is: 1023"
}
