#include "misc.h"
#include <iostream>
#include <string>
#include <thread>
#include "stm32746g_discovery_lcd.h"

void sleepcp(int milliseconds)
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}
void manageSensorOut(DigitalOut sensor){
    sensor = !sensor;
}

void ledOffOn(DigitalOut sensor, DigitalOut led){
    sensor = !sensor;
    string status;
    if(sensor){
        BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
        BSP_LCD_Clear(LCD_COLOR_BLACK);
        BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
        BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
        BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
        BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"Lyset er taendt", CENTER_MODE);
        manageSensorOut(led);
    } else {
        BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
        BSP_LCD_Clear(LCD_COLOR_BLACK);
        BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
        BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
        BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
        manageSensorOut(led);
        BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"Lyset er slukket", CENTER_MODE);
    }
    cout << "Lyset er " + status;
}

int checkSensorStatus(DigitalOut sensor){
    return sensor;
}

void touchLed(DigitalOut sensor){
    sensor = !sensor;
}

void blink(DigitalOut sensor){
    clock_t time_end;
    time_end = clock() + 10000 * CLOCKS_PER_SEC/1000;
    while(clock() < time_end){
        sleepcp(200);
        manageSensorOut(sensor);
    }
}