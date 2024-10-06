#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
    display.begin();
    display.setContrast(57);

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(BLACK);
    display.setCursor(0, 0);
    display.println("Furkan");
    display.display();

display.setTextSize(2);
display.write(3);
display.display();
delay(2000);
display.clearDisplay();
}

void loop() {
    // Loop içinde herhangi bir işlem yok
}
