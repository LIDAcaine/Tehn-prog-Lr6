#include "WORD.h"

void WORD::setword(string wrd)
{
    word = wrd;
}
string WORD::getword() const
{
    return word;
}
void WORD::change()
{
    char ch;
    ch = word[0];
    switch (ch) {
    case 'a':
        word[0] = 'A';
        break;
    case 'o':
        word[0] = 'O';
        break;
    case 'i':
        word[0] = 'I';
        break;
    case 'e':
        word[0] = 'E';
        break;
    case 'u':
        word[0] = 'U';
        break;
    case 'y':
        word[0] = 'Y';
        break;
    }
}

ostream& operator <<(ostream& output, WORD& pointer)
{
    cout << pointer.word;
    return output;
}