class Solution
{
    public:
    void wiggleSort(vector<int>& nums)
    {
        for (int i=1; i<nums.size(); ++i)
        {
            if ((i%2 == 1 && nums[i-1] > nums[i]) ||   // Odd indices  --> should be larger than previous
                (i%2 == 0 && nums[i-1] < nums[i]))     // Even indices --> should be smaller than previous
            {
                swap(nums[i-1], nums[i]);
            }
        }
    }
};