/*
Some times you need to return multiple values from a function.
This is not as convenient as in python and javascript.
Here we have to create a struct.
*/

/*
Like a python dictionary with a predefined shape.
This struct can also be used as a type for variables
and functions, just like int, long, bool etc ...
*/
struct Data
{
    // Here we define variables the struct will contain
    int x;
    int y;
    char z;
};

// Here we define a function that has the Data struct as a return type
Data getData()
{
    // Here we create an instance of the struct with actual data
    Data output{
        output.x = 1,
        output.y = 2,
        output.z = '3',
    };

    return output;
};

// Notice how we still use "Data" as the type for this variable
Data data = getData();

// The contents of a "Data" instance can be accessed with the dot (.) operator
int a = data.x;  // a = 1
int b = data.y;  // b = 2
char c = data.z; // c = '3'
