#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int counter = 0;

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.display();
}

void loop() {
  display.clearDisplay();

  String text = "COUNTER: " + String(counter);
  int16_t x, y;
  uint16_t textWidth, textHeight;

  display.getTextBounds(text, 0, 0, &x, &y, &textWidth, &textHeight);

  int posX = (SCREEN_WIDTH - textWidth) / 2;
  int posY = (SCREEN_HEIGHT - textHeight) / 2;

  display.setCursor(posX, posY);
  display.print(text);
  display.display();

  counter++;
  delay(1000);
}
