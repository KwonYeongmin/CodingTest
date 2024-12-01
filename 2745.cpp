#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int B;
    string str;
    cin >> str >> B;

    int num = 0;
    int start = str.length() - 1;
    for (int k = start; k >= 0; --k)
    {
        if (str[k] >= 'A' && str[k] <= 'Z')
        {
            num += pow(B, start - k)* (str[k] - 'A' + 10);
        }
        else
        {
            num += pow(B, start - k)*(str[k]-'0');
        }
    }
    cout << num;
    return 0;
}
