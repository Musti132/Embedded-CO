#include "mbed.h"

#ifndef __SENSOR_MISC__
#define __SENSOR_MISC__

void manageSensorOut(DigitalOut sensor); // Håndtere sensor status (tænd/sluk) 
int checkSensorStatus(DigitalOut sensor); // Tjek om en sensor er i brug eller ej
void ledOffOn(DigitalOut sensor); // Håndtere knap lyset
void touchLed(DigitalOut sensor); // Håndtere touch lyset
void blink(DigitalOut sensor); // Begynd med at blinke
void sleepcp(int milliseconds); // Wait/sleep/sov

#endif