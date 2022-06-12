class Solution
{
    public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        unordered_set<int> visited;        
        int l=0, r=0, n=nums.size(), currSum=0, maxSum=0;
        while (r < n)
        {
            if (visited.count(nums[r]) == 0)
            {
                visited.insert(nums[r]);
                currSum += nums[r];
                maxSum = max(maxSum, currSum);
                r++;
            }
            else
            {
                while (visited.count(nums[r]) != 0)
                {
                    visited.erase(nums[l]);
                    currSum -= nums[l];
                    l++;
                }
            }
        }
        
        return maxSum;
    }
};