#ifndef TEXT_H
#define TEXT_H

#include <iostream>

using namespace std;

class Text
{
public:
    Text();
    ~Text();
    void symmetrizeLine(string& finalLine, string& initialLine, int maxLengthOfLine);
};

#endif // TEXT_H
