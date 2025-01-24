/*
    Author: Mehmet Furkan KAYA
    Version: 2.0
*/

// LED LIBRARY
#include <FastLED.h>

// LED PINS HEAD //
#define LED_PIN1 7
#define LED_PIN11 8
#define LED_PIN2 9
#define LED_PIN22 10
#define NUM_LEDS1 38
CRGB leds1[NUM_LEDS1];
CRGB leds11[NUM_LEDS1];
CRGB leds2[NUM_LEDS1];
CRGB leds22[NUM_LEDS1];
// LED PINS TAIL //

/*____________________________________________*/
/*_________________ LED HEAD _________________*/
/*____________________________________________*/

void chargingEffect() {
  int delayMs = 10;
  for (int i = 0; i < 100; i++) {
    CRGB color = CRGB(0, 100 - i, 0);
    fill_solid(leds1, NUM_LEDS1, color);
    fill_solid(leds11, NUM_LEDS1, color);
    fill_solid(leds2, NUM_LEDS1, color);
    fill_solid(leds22, NUM_LEDS1, color);
    FastLED.show();
    delay(delayMs);
  }
  for (int i = 100; i >= 0; i--) {
    CRGB color = CRGB(0, 100 - i, 0);
    fill_solid(leds1, NUM_LEDS1, color);
    fill_solid(leds11, NUM_LEDS1, color);
    fill_solid(leds2, NUM_LEDS1, color);
    fill_solid(leds22, NUM_LEDS1, color);
    FastLED.show();
    delay(delayMs);
  }
}
void movingToChargeStationEffect() {
  int delayMs = 10;
  for (int i = 0; i < 50; i++) {
    CRGB color = CRGB(255, i, 0);
    fill_solid(leds1, NUM_LEDS1, color);
    fill_solid(leds11, NUM_LEDS1, color);
    fill_solid(leds2, NUM_LEDS1, color);
    fill_solid(leds22, NUM_LEDS1, color);
    FastLED.show();
    delay(delayMs);
  }
  for (int i = 50; i >= 0; i--) {
    CRGB color = CRGB(255, i, 0);
    fill_solid(leds1, NUM_LEDS1, color);
    fill_solid(leds11, NUM_LEDS1, color);
    fill_solid(leds2, NUM_LEDS1, color);
    fill_solid(leds22, NUM_LEDS1, color);
    FastLED.show();
    delay(delayMs);
  }
}
void loadEffect() {
  CRGB color = CRGB(0, 0, 255);
  int delayMs = 35;
  int mid = NUM_LEDS1 / 2;
  for (int i = 0; i < mid; i++) {
    if (i < mid) {
      leds1[i] = color;
      leds11[i] = color;
      leds2[i] = color;
      leds22[i] = color;
    }
    if (NUM_LEDS1 - 1 - i >= mid) {
      leds1[NUM_LEDS1 - 1 - i] = color;
      leds11[NUM_LEDS1 - 1 - i] = color;
      leds2[NUM_LEDS1 - 1 - i] = color;
      leds22[NUM_LEDS1 - 1 - i] = color;
    }
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds1, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds11, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds2, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds22, NUM_LEDS1, CRGB(0, 0, 0));
  FastLED.show();
}
void unloadEffect() {
  CRGB color = CRGB(0, 0, 255);
  int delayMs = 35;
  int mid = NUM_LEDS1 / 2;
  for (int i = mid - 1; i >= 0; i--) {
    leds1[i] = color;
    leds11[i] = color;
    leds2[i] = color;
    leds22[i] = color;
    leds1[NUM_LEDS1 - 1 - i] = color;
    leds11[NUM_LEDS1 - 1 - i] = color;
    leds2[NUM_LEDS1 - 1 - i] = color;
    leds22[NUM_LEDS1 - 1 - i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds1, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds11, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds2, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds22, NUM_LEDS1, CRGB(0, 0, 0));
  FastLED.show();
}
void rightFillEffect() {
  CRGB color = CRGB(255, 165, 0);
  int delayMs = 15; 
  for (int i = NUM_LEDS1 - 1; i >= 0; i--) {
    fill_solid(leds2, NUM_LEDS1, CRGB(255, 255, 100));
    fill_solid(leds22, NUM_LEDS1, CRGB(255, 255, 100));
    leds1[i] = color;
    leds11[i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds1, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds11, NUM_LEDS1, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}
void leftFillEffect() {
  CRGB color = CRGB(255, 165, 0);
  int delayMs = 15; 
  for (int i = NUM_LEDS1 - 1; i >= 0; i--) {
    fill_solid(leds1, NUM_LEDS1, CRGB(255, 255, 100));
    fill_solid(leds11, NUM_LEDS1, CRGB(255, 255, 100));
    leds2[i] = color;
    leds22[i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds2, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds22, NUM_LEDS1, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}
void goEffect() {
  CRGB color = CRGB(255, 255, 100);
  fill_solid(leds1, NUM_LEDS1, color);
  fill_solid(leds11, NUM_LEDS1, color);
  fill_solid(leds2, NUM_LEDS1, color);
  fill_solid(leds22, NUM_LEDS1, color);
  FastLED.show();
}
void stopEffect() {
  CRGB color = CRGB(255, 0, 0);
  int delayMs = 250;
  fill_solid(leds1, NUM_LEDS1, color);
  fill_solid(leds11, NUM_LEDS1, color);
  fill_solid(leds2, NUM_LEDS1, color);
  fill_solid(leds22, NUM_LEDS1, color);
  FastLED.show();
  delay(delayMs);
  fill_solid(leds1, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds11, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds2, NUM_LEDS1, CRGB(0, 0, 0));
  fill_solid(leds22, NUM_LEDS1, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}

/*____________________________________________*/
/*_________________ LED TAIL _________________*/
/*____________________________________________*/

void setup() {
  // LED SETUP HEAD //
  FastLED.addLeds<WS2812, LED_PIN1, GRB>(leds1, NUM_LEDS1);
  FastLED.addLeds<WS2812, LED_PIN11, GRB>(leds11, NUM_LEDS1);
  FastLED.addLeds<WS2812, LED_PIN2, GRB>(leds2, NUM_LEDS1);
  FastLED.addLeds<WS2812, LED_PIN22, GRB>(leds22, NUM_LEDS1);
  // LED SETUP TAIL //
}

void loop() {
  //rightFillEffect();
  //leftFillEffect();
  //stopEffect();
  //loadEffect();
  //unloadEffect();
  //movingToChargeStationEffect();
  //chargingEffect();
  goEffect();
}