## 정리
- 완전 탐색
- DFS나 재귀 말고 다른 방법을 사용해보자 !!!
- 비슷한 문제를 찾아보자

## 코드
```cpp
    int dfs(const vector<int>& nums, int target, int index, int currentSum) 
    {
        if (index == nums.size()) 
        {
            if(currentSum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        // '+'를 선택한 경우와 '-'를 선택한 경우로 나누어 재귀 호출
        int add = dfs(nums, target, index + 1, currentSum + nums[index]);
        int subtract = dfs(nums, target, index + 1, currentSum - nums[index]);
        
        return add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        if(nums.size() == 1)
        {
            return 1;
        }

        return dfs(nums, target, 0, 0);
    }
```
