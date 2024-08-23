- 이렇게 정렬하는 문제들이 은근 많이 나오는 것 같다
- 매개변수에 들어가는 함수를 구현하는 것이 중요한듯 !! -> ㅅㅁㄱ 코테에서도 비교하는 함수를 구현하는 문제가 나옴.
```cpp
class Solution {
public:
    static bool compare(int a, int b)
{
    string x = to_string(a) + to_string(b);
    string y = to_string(b) + to_string(a);
    return x > y;
}

string largestNumber(vector<int>& nums)
{
    sort(nums.begin(), nums.end(), compare);

    string res = "";
    unsigned long long check = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        res += to_string(nums[i]);
        check += nums[i];
    }

    if(check <= 0)
    {
        return "0";
    }
    return res;
}
};
```
