/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdint>
#include <cstdio>
#include "MyLed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
MyLed led(LED2);
//DigitalOut led(LED2);   //  PTE_26
InterruptIn sw(SW3);
//Ticker ticker;
volatile bool btnPressed = false;
volatile uint16_t counter = 0;


//Thread
Thread led_thread(osPriorityHigh);
//


void rise_handler(void)
{
    led.toggle();
//    led = !led;
    btnPressed = true;
    counter++;
}

/*
void on_tick(void)
{
    led = !led;
}
*/

void led_thread_handler(void)
{
    printf("Led thread in context %p\r\n", ThisThread::get_id());
    while (true) 
    {
        led.toggle();
//        led = !led;
        ThisThread::sleep_for(500ms);
    }
}

int main()
{
//    led = 0;
    printf("MbedOS v %d.%d.%d\r\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    printf("Main thread in context %p\r\n", ThisThread::get_id());
    // Initialise the digital pin LED1 as an output
    led_thread.start(callback(led_thread_handler));
    sw.rise(&rise_handler);
//    ticker.attach(&on_tick, 200ms);

    while (true) {
        if(btnPressed==true)
        {
            printf("Pocet stlaceni tlacidla : %d \r\n", counter);
            btnPressed = false;
        }
        ThisThread::sleep_for(500ms);
    }
}
