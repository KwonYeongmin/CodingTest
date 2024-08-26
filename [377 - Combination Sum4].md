    ```cpp
    int combinationSum4(vector<int>& nums, int target) 
    {
        int res = 0;
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1; 
        for (int i = 1; i <= target; ++i) 
        {
            for (size_t j = 0; j < nums.size(); ++j) 
            {
                // i 값을 만들기 위해
                if (i - nums[j] >= 0) // 조건 검사
                {
                    // 배열의 요소를 더해서 dp에 넣어준다.
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        res = dp[target];
        return res;
    }
    ```
