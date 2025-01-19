/*
    Author: Mehmet Furkan KAYA
    Version: 1.0
*/

#include <FastLED.h>

#define LED_PIN 7
#define NUM_LEDS 144

CRGB leds[NUM_LEDS];

void fillEffect() {
  CRGB color = CRGB(128, 128, 0);
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

void redEffect() {
  CRGB color = CRGB(255, 0, 0);
  int delayMs = 250;
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
  delay(delayMs);
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  delay(delayMs);
}


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  fillEffect();
  //delay(1000);
  //redEffect();
  //delay(1000);
}