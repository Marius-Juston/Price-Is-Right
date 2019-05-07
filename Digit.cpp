//
// Created by mariu on 5/6/2019.
//

#include "Digit.h"
#include "Adafruit_NeoPixel.h"
#include <iostream>

bool numberMatrix[10][8] = {
        {true,  true,  true,  true,  true,  false, true,  true},
        {false, false, true,  true,  false, false, false, true},
        {false, true,  true,  false, true,  true,  true,  true},
        {false, true,  true,  true,  true,  false, true,  true},
        {true,  false, true,  true,  false, false, true,  true},
        {true,  true,  false, true,  true,  false, true,  true},
        {true,  true,  false, true,  true,  true,  true,  true},
        {false, true,  true,  true,  false, false, false, true},
        {true,  true,  true,  true,  true,  true,  true,  true},
        {true,  true,  true,  true,  true,  false, true,  true},
};


void LEDSegment::set(Color color) {
    const int *colors = getColor(color);

    for (int i = startPos; i < endPos; ++i) {
        neoPixel.setPixelColor(i, colors[0], colors[1], colors[2]);
    }
}

LEDSegment::LEDSegment(Segment name, int startPos, int endPos, const Adafruit_NeoPixel &neoPixel) : name(name),
                                                                                                    startPos(startPos),
                                                                                                    endPos(endPos),
                                                                                                    neoPixel(
                                                                                                            neoPixel) {}

Segment LEDSegment::getName() const {
    return name;
}

void Digit::setDigit(int digit, bool hasDot, Color color) {
    for (int i = A; i <= (G + hasDot); ++i) {
        auto segment = static_cast<Segment >(i);

        auto it = segments.find(segment);

        bool isSet = numberMatrix[digit][i];
        if (it != segments.end()) {
            LEDSegment val = it->second;
            if (isSet) {
                val.set(color);
            } else {
                val.set(OFF);
            }

            if (segment == DOT) {
                dotIsOn = hasDot;
            }
        }
    }

    currentDigit = digit;
}


const int Digit::getLedPin() const {
    return ledPin;
}

const int Digit::getNumberOfPixels() const {
    return numberOfPixels;
}

const int Digit::getLedsPerSegment() const {
    return ledsPerSegment;
}

int Digit::getCurrentDigit() const {
    return currentDigit;
}

Digit::Digit(
        const int ledPin,
        const int numberOfPixels,
        const int ledsPerSegment,
        const vector<Segment> &segmentArrangement,
        int currentDigit) : ledPin(ledPin),
                            numberOfPixels(numberOfPixels),
                            ledsPerSegment(ledsPerSegment),
                            currentDigit(currentDigit) {

    neoPixel = Adafruit_NeoPixel(numberOfPixels, ledPin, NEO_GRB + NEO_KHZ800);

    for (int i = 0; i < segmentArrangement.size(); ++i) {
        int start = i * ledsPerSegment;
        int end = start + ledsPerSegment;

        LEDSegment segment(segmentArrangement.at(i), start, end, neoPixel);

        segments.insert(pair<Segment, LEDSegment>(segmentArrangement.at(i), segment));
    }

    dotIsOn = false;

    setDigit(currentDigit, true, OFF);
}

bool Digit::isDotIsOn() const {
    return dotIsOn;
}

void Digit::begin(int brightness) {
    neoPixel.begin();
    neoPixel.setBrightness(brightness);
}

void Digit::show() {
    neoPixel.show();
}

int *getColor(Color digitColor) {
    static int color[3] = {0, 0, 0};

    if (digitColor == RED) { //red
        color[0] = 255;
    } else if (digitColor == GREEN) { //green
        color[1] = 255;
    } else if (digitColor == BLUE) { //blue
        color[2] = 255;
    } else if (digitColor == WHITE) { //white -- careful with this one, 3x power consumption
        color[0] = 255;
        color[1] = 255;
        color[2] = 255;
    } else if (digitColor == YELLOW) { //yellow
        color[0] = 200;
        color[1] = 120;
    }
    return color;
}
