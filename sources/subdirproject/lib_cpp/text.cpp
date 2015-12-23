#include "text.h"

void Text::symmetrizeLine(string& finalLine, string& initialLine, int maxLengthOfLine)
{
        int leftIndent = (maxLengthOfLine - initialLine.size()) / 2;
        finalLine.append(leftIndent, ' ');
        finalLine += initialLine;
}
