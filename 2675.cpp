#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    string outStrArray[10001] ={"",};
    for(int i=0; i<T; ++i)
    {
        int R;
        string str = "";
        cin >> R >> str;
        for(int k=0; k<str.length(); ++k)
        {
            for(int j=0; j<R; ++j)
            {
                outStrArray[i] += str[k];
            }
        }
    }
    
    for(int i=0; i<T; ++i)
    {
        cout << outStrArray[i] << '\n';
    }
    
    return 0;
}
