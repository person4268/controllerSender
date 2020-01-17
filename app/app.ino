#include "wammy.h"
#include "strum.h"
#include "HardwareSerial.h"

void setup()
{
    strum_init();
    wammy_init();
    Serial.begin(9600);
}

void loop()
{
	  strum_read();
    //wammy_read();
}
