class Solution
{
    public:
    int longestSubsequence(vector<int>& nums, int diff)
    {
        unordered_map<int, int> m;
        
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            m[nums[i]] = 1 + m[nums[i] + diff];
            res = max (res, m[nums[i]]);
        }
        return res;
    }
};