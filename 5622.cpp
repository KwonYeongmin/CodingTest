#include <iostream>
#include <string>
using namespace std;

/*
계산
    AW -> 92 2 + 8 + 2 + 1   = 13
    UNUCIC -> 868242 2*6 + 7+5+7+1+3+1 = 36
*/

int GetNumberFromChar(char InCharacter)
{
    switch (InCharacter) {
        case 'A': case 'B': case 'C':
            return 2;
        case 'D': case 'E': case 'F':
            return 3;
        case 'G': case 'H': case 'I':
            return 4;
        case 'J': case 'K': case 'L':
            return 5;
        case 'M': case 'N': case 'O':
            return 6;
        case 'P': case 'Q': case 'R': case 'S':
            return 7;
        case 'T': case 'U': case 'V':
            return 8;
        case 'W': case 'X': case 'Y': case 'Z':
            return 9;
        default:
            return -1; // 알파벳이 아닌 경우
    }
}

int main()
{
    string str;
    cin >> str;
    
    int res = str.length() + str.length();
    // 2+2+6+2+2 -1 

    for(size_t i=0; i<str.length(); ++i)
    {
        int num = GetNumberFromChar(str[i]);
        res += (num-1);
    }
    
    cout << res ;
    
    return 0;
}
