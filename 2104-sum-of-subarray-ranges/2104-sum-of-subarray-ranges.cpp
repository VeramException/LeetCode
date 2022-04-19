class Solution
{
    public:
    long long subArrayRanges(vector<int>& nums)
    {
        long long sum = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            int small = nums[i];
            int large = nums[i];
            for (int j=i+1; j<nums.size(); j++)
            {
                small = min(small, nums[j]);
                large = max(large, nums[j]);
                sum += abs(large - small);
            }
        }
        
        return sum;
    }
};