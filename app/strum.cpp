#include "strum.h"
#include <Arduino.h>
void strum_init() {
    pinMode(STRUM_UP, INPUT);
    pinMode(STRUM_DOWN, INPUT);
    pinMode(STRUM_COMMON, OUTPUT); //Just pulling this to ground because wiring up ground pins is hard
    digitalWrite(STRUM_UP, HIGH); //Pull-Up resistor
    digitalWrite(STRUM_DOWN, HIGH); //Pull-Up resistor
}

void strum_up(bool state) {
    if(state) Serial.write("U");
    else Serial.write("u");
}

void strum_down(bool state) {
    if(state) Serial.write("D");
    else Serial.write("d");
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
