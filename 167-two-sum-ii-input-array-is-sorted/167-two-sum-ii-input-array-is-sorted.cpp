class Solution
{
    public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size()-1;
        
        while (l < r)
        {
            if (target == nums[l] + nums[r])
                return {l+1, r+1};
            
            if (target < nums[l] + nums[r])
                r--;
            else
                l++;
        }
        
        return {};
    }
};