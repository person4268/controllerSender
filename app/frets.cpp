#include "frets.h"
#include <HardwareSerial.h>
#include <Arduino.h>
void frets_init() {
    pinMode(BUTTON_GREEN, INPUT);
    pinMode(BUTTON_RED, INPUT);
    pinMode(BUTTON_YELLOW, INPUT);
    pinMode(BUTTON_BLUE, INPUT);
    pinMode(BUTTON_ORANGE, INPUT);

    digitalWrite(BUTTON_GREEN, HIGH); //Pull-Up resistor
    digitalWrite(BUTTON_RED, HIGH); //Pull-Up resistor
    digitalWrite(BUTTON_YELLOW, HIGH); //Pull-Up resistor
    digitalWrite(BUTTON_BLUE, HIGH); //Pull-Up resistor
    digitalWrite(BUTTON_ORANGE, HIGH); //Pull-Up resistor

}


void button_green(bool state) {
    if(state) Serial.write("Q"); 
    else Serial.write("q");
}

void button_red(bool state) {
    if(state) Serial.write("W"); 
    else Serial.write("w");
}

void button_yellow(bool state) {
    if(state) Serial.write("E"); 
    else Serial.write("e");
}

void button_blue(bool state) {
    if(state) Serial.write("R"); 
    else Serial.write("r");
}

void button_orange(bool state) {
    if(state) Serial.write("T"); 
    else Serial.write("t");
}



bool btnGreenFlag = false;
bool btnGreenToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.
 
bool btnRedFlag = false;
bool btnRedToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.

bool btnYellowFlag = false;
bool btnYellowToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.

bool btnBlueFlag = false;
bool btnBlueToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.

bool btnOrangeFlag = false;
bool btnOrangeToggle = 1; //Toggles on press/release. Used to indicate whether the button was pressed or released.


void frets_read() {
    bool btnGreen = digitalRead(BUTTON_GREEN);
    if(btnGreenFlag != btnGreen) {
        btnGreenToggle = !btnGreenToggle; //Once on press, once on release
        button_green(btnGreenToggle);
        btnGreenFlag = btnGreen;
    }
    bool btnRed = digitalRead(BUTTON_RED);
    if(btnRedFlag != btnRed) {
        btnRedToggle = !btnRedToggle; //Once on press, once on release
        button_red(btnRedToggle);
        btnRedFlag = btnRed;
    }
    bool btnYellow = digitalRead(BUTTON_YELLOW);
    if(btnYellowFlag != btnYellow) {
        btnYellowToggle = !btnYellowToggle; //Once on press, once on release
        button_yellow(btnYellowToggle);
        btnYellowFlag = btnYellow;
    }
    bool btnBlue = digitalRead(BUTTON_BLUE);
    if(btnBlueFlag != btnBlue) {
        btnBlueToggle = !btnBlueToggle; //Once on press, once on release
        button_blue(btnBlueToggle);
        btnBlueFlag = btnBlue;
    }
    bool btnOrange = digitalRead(BUTTON_ORANGE);
    if(btnOrangeFlag != btnOrange) {
        btnOrangeToggle = !btnOrangeToggle; //Once on press, once on release
        button_orange(btnOrangeToggle);
        btnOrangeFlag = btnOrange;
    }

}
