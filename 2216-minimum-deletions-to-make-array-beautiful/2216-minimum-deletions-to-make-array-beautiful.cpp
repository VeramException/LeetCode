class Solution
{
    public:
    int minDeletion(vector<int>& nums)
    {
        int i    = 0;
        int j    = 0;
        int N    = nums.size();
        
        while (j < N)
        {
            nums[i++] = nums[j++]; // Write Even
            while (j < N && nums[i-1] == nums[j]) j++;
            if (j < N)
                nums[i++] = nums[j++]; // Write Odd
        }
        
        if (i % 2)
            i--;
        
        return N-i;
    }
};