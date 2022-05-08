class Solution
{
    public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> res;
        nums.push_back(0);
        for (int i=0; i<nums.size()-1; i++)
        {
            int index = abs(nums[i]);
            if (nums[index] < 0)
                res.push_back(index);
            else
                nums[index] = (nums[index] == 0)? INT_MIN: -abs(nums[index]);
        }
        return res;
    }
};
