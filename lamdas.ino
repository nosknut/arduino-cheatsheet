#define USBCON
#include <Arduino.h>

/*
Lambdas are anonymous functions.
We somewhat have them in python, however they are far less useful.
In languages like JavaScript, lambdas, or arrow functions are far more common.
Google these terms to find more examples.
*/

int accumulate(int values[], int(accumulator)(int total, int value))
{
    int total = 0;
    for (int i = 0; i < sizeof(values); i++)
    {
        total = accumulator(total, values[i]);
    }
    return total;
}

int accumulator(int total, int value)
{
    return total + value;
}

// Using the functions concepts:

int values[] = {1, 2, 3, 4, 5};

int total1 = accumulate(values, accumulator);

int total2 = accumulate(
    values,
    /*
    The following code does the exact same thing as
    the "int accumulator(int total, int value)" above

    Same function arguments as the accumulator() function: total and value
    */
    [](int total, int value)
    {
        // Same code inside this lambda as in the accumulator() function
        return total + value;
    });

//  total1 = 15
//  total2 = 15

/*
If a lambda needs to use a variable from the outside
scope (a variable from the function it was created in),
we need to tell the compiler how to transfer that information
to the lambda.
*/

void outerFunction()
{
    int temperature = 0;
    String unit = "*C";

    /*
     The & operator in the [] below means "pass by reference"
     We can pass by value [=], reference [&],
     or we can specify for each variable we "capture" forom the
     "parent scope" (the body of the "outerFunction()").
     Capturing specific variables looks like this:
     [&temperature, =unit]
     In that example we capture temperature by reference and unit by value.
     
     If we were to to the following inside the lambda:
    
        temperature = 10;
        unit = "*F";
    
    Then the temperature variable would also change inside outerFunction(),
    but the unit variable would only change inside the lambda.
    Passing by reference means we linked the temperature variable inside
    outerFunction() to a new variable with the same name inside the lambda.

    For use cases like this, we are better off using [&] to capture
    everything by reference. That way, the code inside behaves just
    like we would expect when reading it.


    We can also specify the capture-clause ([]) like this: [=unit, &]
    to capture unit by value and everything else by reference.
    */
    auto printTemperature = [&](String message)
    {
        Serial.print(message);
        Serial.print(temperature);
        Serial.println(unit);
    };

    printTemperature("The temperature is: "); // Prints: The temperature is: 0*C
}

/*
NB! The examples below will be easier to understand after
reading the code in the "Object Oriented Programming" folder.

The use of this becomes clear if you have very small tasks that need to be done.
In those cases, having an own function becomes messy. We do have functions like
sum and average, but in some cases our problems are not so straight forward.

Take the following example:
We have a button that we want to run some code on when it is clicked (pressed down, then released).
We could implement this without lambdas, but in some cases, that ends up being less readable.
*/

template <typename Function>
class Button
{
private:
    const int pin;
    bool wasPressed = false;
    // Used in example number 1
    Function onClick;

public:
    Button(const int pin, Function onClickHandler) : pin(pin), onClick(onClickHandler)
    {
    }

    bool isPressed()
    {
        return digitalRead(pin);
    }

    bool wasClicked()
    {
        return wasPressed && !isPressed()
    }

    void setup()
    {
        pinMode(pin, INPUT);
    }

    // Used in example number 2
    template <typename SingleClickHandler>
    void handleClickOnce(SingleClickHandler clickHandler)
    {
        if (wasClicked())
        {
            clickHandler();
        }
    }

    void update()
    {
        if (wasClicked())
        {
            onClick();
        }
        wasPressed = isPressed();
    }
};

///////////////////////////
// Main program starts here

int sensorPin = A0;
Button button(3, [&]()
              {
                  // Code in this function will run when button is clicked
                  Serial.println("Button was clicked");
              });

void setup()
{
    button.setup();
    pinMode(sensorPin, INPUT);
}

///////////////////////////
// Solution if onClick handler is specified in the Button constructor

void loop()
{
    // When the button is clicked, the internal obClick handler
    // will be called inside this update() function
    button.update();
}

///////////////////////////
// Alternative solution if the
// onClick handler needs to use information from the loop()
// A benefit of this solution is that we can have multiple
// independent onClick handlers for each button

void loop()
{
    int sensorValue = analogRead(sensorPin);
    if (sensorValue > 500)
    {
        button.handleClickOnce(
            // We use the [&] capture-clause to capture the sensorValue by reference
            // so that we can change the value of sensorValue inside this clickHandler
            // if we need to later.
            [&]()
            {
                /*
                                   Now that we have specified the lambda onClickHandler inside the loop()
                                   we can include new information from the loop. In this case we have 
                                   included the sensor value in the print.

                                   Warning: We are creating a new lambda every time the code inside this
                                   if-statement runs. That could slow down the code. If you do experience
                                   problems with slow code, try to restructure your code so lambdas are not
                                   created again every time.
                                   */
                Serial.print("Button was clicked with the sensor value: ");
                Serial.println(sensorValue);
            });
    }
    button.update();
}

///////////////////////////
// Alternative solution without lambdas

void loop()
{

    if (button.wasClicked())
    {
        // This code would have run inside the lambda
        Serial.println("Button was clicked");
    }

    button.update();
}

/*
Which solution is better?
As always it comes down to preference, readability and the complexity of the rest of the project.
There is something to be said for keeping your loop function clean.
One must also ask how many buttons are in the system, and if they invoke different events.
If you have 10 buttons that do wildly different things, perhaps it is a good idea to do something like
the onClick handler stored in a button class.
*/