``cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[26] = { 0, };

    for (char ch : str)
    {
        arr[ch - 'a']++;
    }

    for (int i =0; i<26; ++i)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
```
