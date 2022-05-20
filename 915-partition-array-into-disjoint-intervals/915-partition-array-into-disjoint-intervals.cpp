class Solution
{
    public:
    int partitionDisjoint(vector<int>& nums)
    {
        int leftMax = nums[0];
        int nextMax = nums[0];
        int res = 0;        
        
        for (int i=1; i<nums.size(); i++)
        {
            nextMax = max(nextMax, nums[i]);
            
            // We found a smaller than leftMax, include it in the left side.
            if (nums[i] < leftMax)
            {
                res = i;
                leftMax = nextMax;
            }
        }
        
        return res+1;
    }
};