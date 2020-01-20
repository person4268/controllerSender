include "wammy.h"
#include "strum.h"
#include "HardwareSerial.h"
#include "frets.h"
void setup()
{
    strum_init();
    wammy_init();
    frets_init();
    Serial.begin(9600);
}

void loop()
{
	  strum_read();
    frets_read();
    //wammy_read();
    delay(6);
}
