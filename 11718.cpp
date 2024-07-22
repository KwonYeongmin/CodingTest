#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    // 입력 받기
    while(1)
    {
        getline(cin, str);
// getline은 입력된 값이 없는 경우  ""로 저장한다.
        if(str=="")
        {
            break;
        }
        cout << str <<'\n';
    }
    
    return 0;
}
