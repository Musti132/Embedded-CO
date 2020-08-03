#include "misc.h"
#include <iostream>
#include <time.h>
#include "stm32746g_discovery_lcd.h"

//DISCO-F746NG

/*
 * Variables
 */
uint8_t rotateValue[20];
float rotaryValue;

/*
 * Digitals
 */
DigitalOut myled(LED1);
DigitalOut blueLed(D7);
DigitalOut redLed(D6);

/*
 * Analogs
 */
AnalogIn rotator(A0);

/*
 * Interrupts
 */
InterruptIn myBtn(D4);
InterruptIn touch(D5);

DigitalOut buttonLedInUse = redLed; // Which LED to use for the button
DigitalOut touchLedInUse = blueLed; // Which LED to use for the touch


void handleCallbackBtn(){
    ledOffOn(buttonLedInUse);
}

void handleCallbackTouch(){
    blink(touchLedInUse);
}

int main() {
    /*
     *  Handle callback function for rising state
     */ 
    myBtn.rise(handleCallbackBtn);
    touch.rise(handleCallbackTouch); 

    /*
     * Turn on screen with a welcome screen
     */
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    BSP_LCD_Clear(LCD_COLOR_GREEN);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"Loaded LCD screen", CENTER_MODE);
    BSP_LCD_DisplayStringAt(0, LINE(2), (uint8_t *)"Made by Mustafa", LEFT_MODE);
    while (true) {
        rotaryValue = rotator.read() * 100;
        sprintf((char*)rotateValue, "Rotater value: %i", (int)rotaryValue);
        BSP_LCD_DisplayStringAt(0, LINE(10), (uint8_t *)&rotateValue, LEFT_MODE);
        
    }
}

/*
void manageSensorIn(int status, DigitalIn sensor){
    sensor = status;
}*/
