class Solution
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;        
        vector<int> combNums = nums;
        do
        {
            res.push_back(combNums);
            nextPermutation(combNums);
        } while (combNums != nums);
        
        return res;
    }
    
    void nextPermutation (vector<int>& nums)
    {
        int n = nums.size();
        
        // Step-1: Find 'i' such that nums[i] < nums[i+1]
        int i;
        for (i=n-2; i>=0; i--)
            if (nums[i] < nums[i+1])
                break;

        if (i<0) // we reached the last permutation
            reverse(nums.begin(), nums.end());
        else
        {
            // Step-2: Find 'j' such that nums[j] > nums[i]
            int j;
            for (j=n-1; j>i; j--)
                if (nums[j] > nums[i])
                    break;
            
            // Step-3: Swap nums[i], nums[j]
            swap(nums[i], nums[j]);
            
            // Step-4: reverse sub-array nums[i+1]
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};