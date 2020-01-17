#include "strum.h"
#include <Arduino.h>
void strum_init() {
    pinMode(STRUM_UP, INPUT);
    pinMode(STRUM_DOWN, INPUT);
    pinMode(STRUM_COMMON, OUTPUT); //Just pulling this to ground because wiring up ground pins is hard
    digitalWrite(STRUM_UP, HIGH); //Pull-Up resistor
    digitalWrite(STRUM_DOWN, HIGH); //Pull-Up resistor
}
/**
 * Sends the value to the reciever. Temporaily, this is the serial console. 
*/
void strum_up(bool state) {
    Serial.write("U");
}

/**
 * Sends the value to the reciever. Temporaily, this is the serial console. 
*/
void strum_down(bool state) {
    Serial.write("D");
}

bool strumUpFlag = false;
bool strumUpToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.
 
bool strumDownFlag = false;
bool strumDownToggle = 1;

void strum_read() {
    bool strumUp = digitalRead(STRUM_UP);
    if(strumUpFlag != strumUp) {
        strumUpToggle = !strumUpToggle; //Once on press, once on release
        strum_up(strumUpToggle);
        strumUpFlag = strumUp;
    }

    bool strumDown = digitalRead(STRUM_DOWN);
    if(strumDownFlag != strumDown) {
        strumDownToggle = !strumDownToggle; //Once on press, once on release
        strum_down(strumDownToggle);
        strumDownFlag = strumDown;
    }
}
