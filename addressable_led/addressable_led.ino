/*
    Author: Mehmet Furkan KAYA
    Version: 1.0
*/

// LED LIBRARY
#include <FastLED.h>

// LED PINS HEAD //
#define LED_PIN 7
#define NUM_LEDS 144
CRGB leds[NUM_LEDS];
// LED PINS TAIL //

/*____________________________________________*/
/*_________________ LED HEAD _________________*/
/*____________________________________________*/

void chargingEffect() {
  for (int i = 0; i < 255; i++) {
    CRGB color = CRGB(0, 255 - i, 0);
    fill_solid(leds, NUM_LEDS, color);
    FastLED.show();
  }
  for (int i = 255; i >= 0; i--) {
    CRGB color = CRGB(0, 255 - i, 0);
    fill_solid(leds, NUM_LEDS, color);
    FastLED.show();
  }
}
void movingToChargeStationEffect() {
  for (int i = 0; i < 150; i++) {
    CRGB color = CRGB(255, i, 0);
    fill_solid(leds, NUM_LEDS, color);
    FastLED.show();
  }
  for (int i = 150; i >= 0; i--) {
    CRGB color = CRGB(255, i, 0);
    fill_solid(leds, NUM_LEDS, color);
    FastLED.show();
  }
}
void loadEffect() {
  CRGB color = CRGB(0, 0, 255);
  int delayMs = 10;
  int mid = NUM_LEDS / 2;
  for (int i = 0; i < mid; i++) {
    if (i < mid) leds[i] = color;
    if (NUM_LEDS - 1 - i >= mid) leds[NUM_LEDS - 1 - i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}
void unloadEffect() {
  CRGB color = CRGB(0, 0, 255);
  int delayMs = 10;
  int mid = NUM_LEDS / 2;
  for (int i = mid - 1; i >= 0; i--) {
    leds[i] = color;
    leds[NUM_LEDS - 1 - i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}
void rightFillEffect() {
  CRGB color = CRGB(255, 165, 0);
  int delayMs = 1; 
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}
void leftFillEffect() {
  CRGB color = CRGB(255, 165, 0);
  int delayMs = 1; 
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = color;
    FastLED.show();
    delay(delayMs);
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}
void goEffect() {
  CRGB color = CRGB(255, 255, 100);
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
}
void stopEffect() {
  CRGB color = CRGB(255, 0, 0);
  int delayMs = 250;
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
  delay(delayMs);
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}

/*____________________________________________*/
/*_________________ LED TAIL _________________*/
/*____________________________________________*/

void setup() {
  // LED SETUP HEAD //
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  // LED SETUP TAIL //
}

void loop() {
  //rightFillEffect();
  //leftFillEffect();
  //delay(1000);
  //stopEffect();
  //delay(1000);
  //loadEffect();
  //unloadEffect();
  //movingToChargeStationEffect();
  chargingEffect();
  //goEffect();
}