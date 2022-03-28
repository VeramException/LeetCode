class Solution
{
    public:
    bool search(vector<int>& nums, int target)
    {
        int N = nums.size();

        for (int val: nums)
        {
            if (val == target)
                return true;
        }
        
        return false;
    }
};