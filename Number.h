//
// Created by mariu on 5/6/2019.
//

#ifndef PRICE_IS_RIGHT_NUMBER_H
#define PRICE_IS_RIGHT_NUMBER_H

#include <vector>
#include <ostream>
#include "Digit.h"

using namespace std;

class Number {
    int numberOfDigits;
    int currentNumber;
    vector<Digit> digits;
    int dotDigitIndex;
public:
    explicit Number(int numberOfDigits,
                    const int *pins,
                    const int *numberOfPixels,
                    const int *numberOfPixelsPerSegment,
                    const vector<Segment> &digitSegmentArrangement,
                    const vector<Segment> &dotDigitSegmentArrangement,
                    int dotDigitIndex = -1,
                    int currentDigit = 0);

    friend ostream &operator<<(ostream &os, const Number &number);

    void setNumber(int number, Color color = WHITE);

    void begin(int brightness);

    void show();
};


#endif //PRICE_IS_RIGHT_NUMBER_H
