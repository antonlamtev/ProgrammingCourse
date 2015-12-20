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
    string error;
public:
    CoordinatesException(const char* error) : error(error){}

    string getError() const
    {
        return error;
    }
};

class Queen
{    
    int letter;
    int numeral;
    const char* ERROR_BAD_COORDINATES = "ERROR: wrong queens coordinates";
public:
    Queen(int letter, int numeral): letter(letter), numeral(numeral)
    {
        if (letter < A || letter > H || numeral < 1 || numeral > 8)
        {
            throw CoordinatesException(ERROR_BAD_COORDINATES);
        }
    }
    Queen();
    ~Queen();
    bool amIBeat(Queen queen) const;
};

#endif // QUEENS_H
