class Solution
{
    public:
    void nextPermutation(vector<int>& nums)
    {
        // Step-1
        // Find  the last 'i' such that nums[i] < nums[i+1]
        int i;
        for (i = nums.size()-2; i>=0; i--)
        {
            if (nums[i] < nums[i+1])
                break;
        }
        
        // if no such 'i' is found, it means that this is the last permutation. 
        // so just return the first permutation
        if (i<0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step-2
        // Find last j , such that nums[i] < nums[j]
        int j;
        for (j=nums.size()-1; j>i; j--)
        {
            if (nums[i] < nums[j])
                break;
        }
        
        // Step-3
        // swap nums[i], nums[j]
        swap(nums[i], nums[j]);
        
        // Step-4
        // Reverse i+1 to end()
        reverse(nums.begin()+i+1, nums.end());
    }
};