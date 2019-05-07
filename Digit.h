//
// Created by mariu on 5/6/2019.
//

#ifndef PRICE_IS_RIGHT_DIGIT_H
#define PRICE_IS_RIGHT_DIGIT_H

#include <map>
#include <ostream>
#include "Adafruit_NeoPixel.h"
#include <vector>

using namespace std;

enum Color {
    OFF, RED, GREEN, BLUE, WHITE, YELLOW
};

enum Segment {
    A, B, C, D, E, F, G, DOT
};


class LEDSegment {

    Segment name;
    int startPos;
    int endPos;
    Adafruit_NeoPixel neoPixel;
public:
    LEDSegment(Segment name, int startPos, int endPos, const Adafruit_NeoPixel &neoPixel);

    void set(Color color);

    Segment getName() const;


};

class Digit {
    const int ledPin;
    const int numberOfPixels;
    const int ledsPerSegment;
    int currentDigit;
    bool dotIsOn;
    Adafruit_NeoPixel neoPixel;
    std::map<Segment, LEDSegment> segments;
public:
    Digit(int ledPin, int numberOfPixels, int ledsPerSegment,
          const vector<Segment> &segments, int currentDigit = 0);

    void setDigit(int digit, bool hasDot = false, Color color = WHITE);

    const int getLedPin() const;

    const int getNumberOfPixels() const;

    const int getLedsPerSegment() const;

    bool isDotIsOn() const;

    int getCurrentDigit() const;

    void begin(int brightness);

    void show();
};

int *getColor(Color digitColor);


#endif //PRICE_IS_RIGHT_DIGIT_H
