class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int l = 0, r = 0;
        
        while (r < nums.size())
        {
            if (nums[r] != 0)
                nums[l++] = nums[r++];
            else
                r++;
        }
        
        while (l < nums.size())
            nums[l++] = 0;
    }
};