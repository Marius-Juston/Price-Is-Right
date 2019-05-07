//
// Created by mariu on 5/6/2019.
//

#include "Number.h"


Number::Number(int numberOfDigits,
               const int *pins,
               const int *numberOfPixels,
               const int *numberOfPixelsPerSegment,
               const vector<Segment> &digitSegmentArrangement,
               const vector<Segment> &dotDigitSegmentArrangement,
               int dotDigitIndex, int currentNumber) : numberOfDigits(numberOfDigits), dotDigitIndex(dotDigitIndex),
                                                       currentNumber(currentNumber) {

    for (int i = 0; i < numberOfDigits; ++i) {

        vector<Segment> seg;

        if (dotDigitIndex == i) {
            seg = dotDigitSegmentArrangement;
        } else {
            seg = digitSegmentArrangement;
        }

        Digit digit(pins[i], numberOfPixels[i], numberOfPixelsPerSegment[i], seg);

        digits.emplace_back(digit);
    }

    setNumber(currentNumber);
}

ostream &operator<<(ostream &os, const Number &number) {
    string output;

    for (const auto &digit : number.digits) {
        if (digit.isDotIsOn()) {
            output += '.';
        }

        output += to_string(digit.getCurrentDigit());
    }

    os << output;
    return os;
}

void Number::setNumber(int number, Color color) {
    for (int i = numberOfDigits - 1; i >= 0; --i) {
        int digit = number % 10;

        digits.at(i).setDigit(digit, (i == dotDigitIndex) && (i != 0), color);

        number /= 10;
    }

    currentNumber = number;
}

void Number::begin(int brightness) {
    for (auto &digit : digits) {
        digit.begin(brightness);
    }
}

void Number::show() {
    for (auto &digit : digits) {
        digit.show();
    }
}

