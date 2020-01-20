#include "buttons.h"
#include <HardwareSerial.h>
#include <Arduino.h>
void buttons_init() {
    pinMode(BUTTON_SELECT, INPUT);
    pinMode(BUTTON_START, INPUT);
    pinMode(BUTTON_COMMON, INPUT);

    digitalWrite(BUTTON_COMMON, LOW); // Pull to ground
    digitalWrite(BUTTON_SELECT, HIGH); //Pull-Up resistor
    digitalWrite(BUTTON_START, HIGH); //Pull-Up resistor
}


void button_select(bool state) {
    if(state) Serial.write("L"); 
    else Serial.write("l");
}

void button_start(bool state) {
    if(state) Serial.write("K"); 
    else Serial.write("k");
}

bool btnSelectToggle = false;
bool btnSelectToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.
 
bool btnStartFlag = false;
bool btnStartToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.

void buttons_read() {
    bool btnSelect = digitalRead(BUTTON_SELECT);
    if(btnSelectToggle != btnSelect) {
        btnSelectToggle = !btnSelectToggle; //Once on press, once on release
        button_select(btnSelectToggle);
        btnSelectToggle = btnSelect;
    }
    bool btnStart = digitalRead(BUTTON_START);
    if(btnStartFlag != btnStart) {
        btnStartToggle = !btnStartToggle; //Once on press, once on release
        button_start(btnStartToggle);
        btnStartFlag = btnStart;
    }
}
