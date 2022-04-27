class Solution
{
    private:
    unordered_map<int, unordered_map<int, bool>> cache;
    
    public:
    bool canPartition(vector<int>& nums)
    {
        if (nums.size() == 1)
            return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum%2) // And odd sum cannot be split into 2 equal subsets.
            return false;
        
        int target = sum/2;
        
        return dfs(nums, 0, 0, target);
    }
    
    bool dfs(vector<int>& nums, int i, int currSum, int target)
    {
        if (currSum == target)
            return true;
        
        if (currSum > target || i >= nums.size())
            return false;

        if (cache.count(i) && cache[i].count(currSum))
            return cache[i][currSum];
            
        cache[i][currSum] = dfs(nums, i+1, currSum+nums[i], target) ||  dfs(nums, i+1, currSum, target);
        
        return cache[i][currSum];
    }
};