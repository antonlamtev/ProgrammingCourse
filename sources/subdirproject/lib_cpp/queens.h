#ifndef QUEENS_H
#define QUEENS_H

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

using namespace std;

enum WhoBeats {NO_ONE = 0, EVERYONE, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};

enum CoordinateLetter {A = 1, B, C, D, E, F, G, H};

class CoordinatesException : public exception
{
    int letter;
    int numeral;
public:
    CoordinatesException(int letter, int numeral) : letter(letter), numeral(numeral){}

    int getLetter() const
    {
        return letter;
    }

    int getNumeral() const
    {
        return numeral;
    }
};

class Queen
{    
    int letter;
    int numeral;

public:
    Queen(int letter = A, int numeral = 1);
    bool amIBeat(Queen queen) const;
};

class ThreeQueens
{
public:
    static WhoBeats whoBeats(Queen q1, Queen q2, Queen q3);
};

#endif // QUEENS_H
