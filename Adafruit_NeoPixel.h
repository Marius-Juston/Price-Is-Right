//
// Created by mariu on 5/6/2019.
//

#ifndef PRICE_IS_RIGHT_ADAFRUIT_NEOPIXEL_H
#define PRICE_IS_RIGHT_ADAFRUIT_NEOPIXEL_H

#include <ostream>

static const int NEO_GRB = 0;
static const int NEO_KHZ800 = 1;


class Adafruit_NeoPixel {
public:
    Adafruit_NeoPixel();

    Adafruit_NeoPixel(int numberOfPixels, int ledPin, int type);

    void begin();

    void setBrightness(int brightness);

    void show();

    void setPixelColor(int ledPos, int reg, int green, int blue);

};


#endif //PRICE_IS_RIGHT_ADAFRUIT_NEOPIXEL_H
