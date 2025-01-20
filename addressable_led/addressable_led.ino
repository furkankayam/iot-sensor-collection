/*
    Author: Mehmet Furkan KAYA
    Version: 1.0
*/

#include <FastLED.h>

#define LED_PIN 7
#define NUM_LEDS 144

CRGB leds[NUM_LEDS];

void chargeEffect() {
  int delayMs = 50;  // Efektin hızını ayarlamak için bu değeri değiştirebilirsiniz
  int ledsPerStep = 5;  // Her adımda 5 LED kayacak

  for (int i = 0; i < NUM_LEDS; i += ledsPerStep) {
    // Kırmızıdan turuncuya geçiş yapmak için RGB değerlerini değiştiriyoruz
    for (int j = 0; j < ledsPerStep && i + j < NUM_LEDS; j++) {
      int redValue = 255;  // Kırmızı sabit kalır
      int greenValue = map(i + j, 0, NUM_LEDS - 1, 0, 165);  // Yeşil değerini artırıyoruz
      CRGB color = CRGB(redValue, greenValue, 0);  // Mavi sabit 0 kalır

      leds[i + j] = color;  // Her bir LED'e renk atıyoruz
    }

    FastLED.show();
    delay(delayMs);
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

void yellowEffect() {
  CRGB color = CRGB(255, 255, 0);
  int delayMs = 1;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
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
  //loadEffect();
  //unloadEffect();
  //chargeEffect();
  //yellowEffect();
}