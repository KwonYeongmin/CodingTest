## 문제
https://school.programmers.co.kr/learn/courses/30/lessons/42747#
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// h의 최댓값이 이 과학자의 H-Index
int solution(vector<int> citations) 
{
    int x = citations[0];
    
    sort(citations.begin(), citations.end());
    
    int left = 0;
    int right = citations[citations.size()-1];
    
    int answer = 0;
    
    for(int i=left; i<=right; ++i)
    {
        x = i;
        int count = 0;
        
        for(int j=0; j<citations.size(); ++j)
        {
            if(x <= citations[j]) 
            {
                ++count;
            }
        }
        if(count >= x) 
        {
            answer = max(answer,x);
        }
    }
    
    return answer;
}
```
