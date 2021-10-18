#ifndef __MyLed_H
#define __MyLed_H

#include "mbed.h"

class MyLed
{
private:
    DigitalOut led;
public:
    MyLed(PinName pin);
    ~MyLed();
    void set(bool s);
    void toggle(void);
};



#endif