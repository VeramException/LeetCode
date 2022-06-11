class Solution
{
    public:
    int minOperations(vector<int>& nums, int target)
    {
        int sum = 0;
        for (int num: nums)
            sum += num;
        
        // Find the longest sub-array whose sum = target
        int l = 0;
        int r = 0;
        int n = nums.size();
        int res = INT_MAX;
        
        while (l <= r)
        {
            if (sum >= target)
            {
                if (sum == target)
                    res = min (res, l + n - r);
                
                if (r < n)
                    sum = sum - nums[r++];
                else
                    break;                    
            }
            else
                sum = sum + nums[l++];
        }
        return (res == INT_MAX)? -1: res;
    }
};