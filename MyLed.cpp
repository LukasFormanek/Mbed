#include "MyLed.h"

MyLed::MyLed(PinName pin)
: led(pin)
{
    led=0;
}

MyLed::~MyLed()
{
}

void MyLed::set(bool s)
{
    if (s)
        led = 1;
    else
        led = 0;
}

void MyLed::toggle()
{
    led = !led;
}
