auto getData()
{
    /*
    Here we are creating an unnamed structs with default
    values. That way we don't have to specify everything twice.
    Do take a moment to consider how this could be confusing
    or difficult to scale before using it though.
    */
    struct
    {
        int x = 1;
        int y = 2;
        char z = '3';
    } output;

    return output;
};

auto data = getData();

int a = data.x;  // a = 1
int b = data.y;  // b = 2
char c = data.z; // c = '3'
