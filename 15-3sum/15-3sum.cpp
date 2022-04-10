class Solution
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        
        int N = nums.size();
        if (N<3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<N-2; i++)
        {
            // ignore duplicates
            if (i>0 && nums[i-1]==nums[i])
                continue;
            
            int twoSumTarget = 0 - nums[i];
            int l = i+1;
            int r = N-1;
            while (l < r)
            {
                if (nums[l]+nums[r] == twoSumTarget)
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                
                    // ignore duplicates
                    while (l<r && nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;
                    
                    l++;
                    r--;
                }
                else if (nums[l]+nums[r] > twoSumTarget)
                    r--;
                else
                    l++;
            }            
        }  
        
        return res;
    }
};