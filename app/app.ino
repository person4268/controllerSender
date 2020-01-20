#include "wammy.h"
#include "strum.h"
#include "frets.h"
#include "buttons.h"
#include <Arduino.h>
void setup()
{
    strum_init();
    wammy_init();
    frets_init();
    buttons_init();
    Serial.begin(9600);
}

void loop()
{
	  strum_read();
    frets_read();
    buttons_read();
    //wammy_read();
    delay(6);
}
