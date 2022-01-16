class SerialController
{
public:
    virtual void print(const char str[]);
    virtual void println(const char str[]);
    virtual void begin(int baudRate);
    virtual char *readString();
};
