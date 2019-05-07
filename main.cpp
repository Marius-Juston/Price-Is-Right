#include "Digit.h"
#include "Number.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<Segment> segment;
    segment.push_back(G);
    segment.push_back(F);
    segment.push_back(A);
    segment.push_back(B);
    segment.push_back(C);
    segment.push_back(D);
    segment.push_back(E);

    vector<Segment> dotSegment;
    dotSegment.push_back(G);
    dotSegment.push_back(F);
    dotSegment.push_back(A);
    dotSegment.push_back(B);
    dotSegment.push_back(C);
    dotSegment.push_back(D);
    dotSegment.push_back(E);
    dotSegment.push_back(DOT);

    int pins[] = {0, 1, 2};
    int numberOfPixels[] = {24, 24, 24};
    int numberOfPixelsPerSegment[] = {4, 4, 4};

    Number number(3, pins, numberOfPixels, numberOfPixelsPerSegment, segment, dotSegment, 2);

    for (int i = 0; i <= 999; ++i) {
        number.setNumber(i);
        cout << number << endl;
    }


    return 0;
}