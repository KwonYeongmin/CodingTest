### 조건
- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
```cpp
#include <iostream>
using namespace std;

int N,M;
int arr[10] ;
bool isUsed[10] ;

void func(int k)
{
  if(k==M)
  {
    for(int i=0; i<M; ++i)
    {
      cout << arr[i] <<' ';
    }
    cout << '\n';
    return;
  }

  // 1부터 N까지
  for(int i=1; i<=N; ++i)
  {
    if(false == isUsed[i])
    {
      arr[k] = i;
      isUsed[i] = true;
      func(k+1);
      isUsed[i] = false;
    }
  }
}

int main()
{
  cin >> N >>M;
  func(0);
  return 0;
}

```
