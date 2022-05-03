class Solution
{
    public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        int start = -1;
        int end   = -1;
    
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] != sortedNums[i])
            {
                if (start == -1)
                    start = i;
                else
                    end = i;
            }            
        }
        
        return (start == -1)? 0: end-start+1;
    }
};
