#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 문자열 입력   
    string str;
	getline(cin,str);
	
    // 공백만 입력된 경우
    if(str.length() == 1 && str[0] ==' ')
    {
        cout << 0;
        return 0;
    }
    
    // 개수 세기 
    // 마지막 공백일 수 있으니까 마지막 문자는 확인하지 않는다.
    int cnt = 1;
    for(int i=1; i<str.length()-1; ++i)
    {
        if(str[i] == ' ')
        {
            ++cnt;
        }
    }
    
    cout << cnt;
    
    return 0;
}
