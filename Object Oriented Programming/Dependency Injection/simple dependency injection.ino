#define USBCON
#include <Arduino.h>

class Thing
{
};

class OtherThing
{
private:
    const Thing thing;

public:
    OtherThing(Thing thing) : thing(thing)
    {
    }

    Thing getThing()
    {
        return thing;
    }
};

/*
Because we instansiate Thing() directly in the parameter list of OtherThing,
we must explicitly call the constructor of OtherThing() by writing
    
    Type variableName = Type(parameterList);

instead of
    
    Type variableName(parameterList);
*/
OtherThing otherThing = OtherThing(Thing());

void setup()
{
    Thing thing = otherThing.getThing();
}
