#include "misc.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "stm32746g_discovery_lcd.h"

void sleepcp(int milliseconds)
{
    /*
     * Wait function
     */ 
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}
void manageSensorOut(DigitalOut sensor){
    sensor = !sensor;
}

void ledOffOn(DigitalOut sensor){
    sensor = !sensor;
    string status;

    // Check if sensor is on or off, then display the status
    if(sensor){
        BSP_LCD_DisplayStringAt(0, LINE(4), (uint8_t *)"Red LED: on", CENTER_MODE);
    } else {
        BSP_LCD_DisplayStringAt(0, LINE(4), (uint8_t *)"Red LED: off", CENTER_MODE);
    }
}

int checkSensorStatus(DigitalOut sensor){
    return sensor;
}

void touchLed(DigitalOut sensor){
    sensor = !sensor;
}

void blink(DigitalOut sensor){
    // Blink the LED for 10 seonds
    int test = 0;
    clock_t time_end;
    uint8_t elapsedSeconds[35];
    time_end = clock() + 10000 * CLOCKS_PER_SEC/1000;

    while(clock() < time_end){

        //Print out time elapsed
        sprintf((char*)elapsedSeconds, "Elapsed Seconds: %i", (int)test);
        BSP_LCD_DisplayStringAt(0, LINE(3), (uint8_t *)&elapsedSeconds, LEFT_MODE);

        //Apped to the "timer"
        test++;

        sleepcp(1000);
        manageSensorOut(sensor);
    }
}