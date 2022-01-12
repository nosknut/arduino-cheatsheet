class Thing
{
};

class OtherTing
{
    const Thing thing;

    OtherThing(Thing thing) : thing(thing)
    {
    }

    Thing getThing()
    {
        return thing;
    }
};

OtherThing otherThing(Thing());

Thing thing = otherThing.getThing();
