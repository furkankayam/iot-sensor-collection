#include "DigiKeyboard.h"

void setup() {
    DigiKeyboard.delay(2000);

    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);

    DigiKeyboard.print("https://furkankayam.github.io/furkankaya.github.io/");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
}
