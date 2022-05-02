class Solution
{
    public:
    
    // O(n)
    int findKthPositive(vector<int>& nums, int k)
    {
        int expected = 1;
        int i = 0;
        
        while (i < nums.size())
        {
            if (nums[i] != expected)
            {
                if (--k == 0)
                    return expected;
                expected++;
            }
            else
            {
                expected++;
                i++;
            }
        }
        
        return expected+k-1;
    }
};