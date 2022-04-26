class Solution
{
    public:
    int subarraySum(vector<int>& nums, int k)
    {
        int res = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1; // base case
        
        int currSum = 0;
        for (int num: nums)
        {
            currSum  += num;
            res      += prefixSums[currSum - k];
            prefixSums[currSum]++;
        }
        
        return res;
    }
};