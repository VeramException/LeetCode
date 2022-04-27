class Solution
{
    public:
    void wiggleSort(vector<int>& nums)
    {
        vector<int> sorted(nums);
        sort (sorted.begin(), sorted.end());
        
        int n = nums.size();

        int j = (n-1)/2;
        int k = n-1;
        for (int i=0; i<n; i++)
        {
            if (i%2)                      // Odd indices
                nums[i] = sorted[k--];
            else                          // Even indices
                nums[i] = sorted[j--];
        }
    }
};