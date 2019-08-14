#include "wammy.h"
#include <Arduino.h>

void wammy_init() {
    pinMode(WAMMY_PIN, INPUT);
}
/**
 * Sends the value to the reciever. Temporaily, this is the serial console. 
*/
void wammy_send(int value) {
    Serial.write("[WAMMY]: ");
    Serial.print(value, DEC);
    Serial.write("\n");
}

int lastVal = 0;
void wammy_read() {
    int wammyVal = analogRead(WAMMY_PIN);
    if(lastVal != wammyVal) {
        wammy_send(wammyVal);
        lastVal = wammyVal;
    }
}