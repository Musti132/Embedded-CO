#include "misc.h"
#include <iostream>
#include <time.h>
#include "stm32746g_discovery_lcd.h"

//DISCO-F746NG
DigitalOut myled(LED1);
DigitalOut newLed(D7);
DigitalOut redLed(D6);

InterruptIn myBtn(D2);
InterruptIn touch(D5);

DigitalOut ledInUse = myled; // Hvilken led der skal bruges til knappen
DigitalOut touchInUse = newLed; // Hvilken led der skal bruges til knappen

bool test = false;
bool onOff = false;
bool pressed = false;
bool blinking = false;

void handleCallbackBtn(){
    DigitalOut led = ledInUse;
    onOff = true;
    ledOffOn(led, newLed);
}
/*
void handleCallbackTouch(){
    DigitalOut new_led = touchInUse;
    touchLed(new_led);
}
*/
void handleCallbackTouch(){
    DigitalOut new_led = touchInUse;
    
    blink((DigitalOut) new_led);
    
}

int main() {
    /*
     *  Give nogen funktioner til de forskellige komponenter sat til maskinen
     */ 
    myBtn.rise(handleCallbackBtn);
    touch.rise(handleCallbackTouch); 

    /*
     * Tænd for skærmen
     */
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    while (true) {
        
    }
}

/*
void manageSensorIn(int status, DigitalIn sensor){
    sensor = status;
}*/
