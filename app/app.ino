#include "wammy.h"
#include "strum.h"
#include "HardwareSerial.h"
#include "buttons.h"
void setup()
{
    strum_init();
    wammy_init();
    buttons_init();
    Serial.begin(9600);
}

void loop()
{
	  strum_read();
      buttons_read();
    //wammy_read();
    delay(6);
}
