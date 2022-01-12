//Enums:
// https://playground.arduino.cc/Code/Enum/
enum class Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

void turnTowards(Direction direction)
{
    switch (direction)
    {
    case Direction::NORTH:
        // Turn North
        break;
    case Direction::SOUTH:
        // Turn South
        break;
    case Direction::EAST:
        // Turn East
        break;
    case Direction::WEST:
        // Turn West
        break;
    }
}

void loop()
{
    turnTowards(Direction::NORTH);

    // Samme example but with if-else-statements
    Direction direction = Direction::NORTH;

    if (direction == Direction::NORTH)
    {
        // Turn North
    }
    else if (direction == Direction::SOUTH)
    {
        // Turn South
    }
    else if (direction == Direction::EAST)
    {
        // Turn East
    }
    else if (direction == Direction::WEST)
    {
        // Turn West
    }
    else
    {
        /* Will never run.
        There are only 4 directions possible because the enum
        only contains 4 values.

        It is impossible for "direction" to not be one of the 4
        values above.
        */
    }
}
