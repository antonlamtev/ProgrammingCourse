#include "text.h"

Text::Text()
{

}

Text::~Text()
{

}

void Text::symmetrizeLine(string& finalLine, string& initialLine, int maxLengthOfLine)
{
        int leftIndent = (maxLengthOfLine - initialLine.size()) / 2;
        finalLine.append(leftIndent, ' ');
        finalLine += initialLine;
//        memset(finalLine, ' ', leftIndent);
//        strcat(finalLine, initialLine);
}
