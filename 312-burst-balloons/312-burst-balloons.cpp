class Solution
{
    public:
    int cache[301][301];
    
    int maxCoins(vector<int>& nums)
    {
        // Cool intuition - https://www.youtube.com/watch?v=VFskby7lUbw
        
        // The main idea is we consider that each value is popped at the last.
        
        //        L        R
        // Eg: 1 [3, 1, 5, 8] 1
        // If we pop '3' at last, then maxCoins = (nums[L-1] x 3 x nums[R+1]) + DP[L+1, R]
        //
        //
        // Assume 'i' is somewhere in the middle
        //        L  i     R
        // Eg: 1 [3, 1, 5, 8] 1
        // Then maxSum if we pop i'th value at last = DP[L, i-1] + (nums[L-1] x 1 x nums[R+1]) + DP[i+1, R]
        
        // Time complexity: We assume that each value is popped at last        = O(n).
        //                  And then we take all subarrays on the left & right = O(n^2).
        //                                                           So, total = O(n^3).
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int N = nums.size();
        memset(cache, -1, sizeof(cache));

        return dfs(nums, 1, N-2);
    }
    
    int dfs(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return 0;
        
        if (cache[l][r] != -1)
            return cache[l][r];
        
        for (int i=l; i<=r; i++)
        {
            int coins = dfs(nums, l, i-1)                 // coins of left side sub-arrays
                        + nums[l-1] * nums[i] * nums[r+1] // coins if we pick the i'th value last.
                        + dfs(nums, i+1, r);              // coins of right side sub-arrays
            cache[l][r] = max (cache[l][r], coins);
        }
        
        return cache[l][r];
    }
};
