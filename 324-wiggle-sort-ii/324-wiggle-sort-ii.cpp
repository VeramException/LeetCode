class Solution
{
    public:
    void wiggleSort(vector<int>& nums)
    {
        vector<int> sorted(nums);
        sort (sorted.begin(), sorted.end());
        
        int n = nums.size();
        
        for (int i=0, j=(n-1)/2, k=n-1; 
                 i<n;
                 i++)
        {
            if (i%2)
                nums[i] = sorted[k--];
            else
                nums[i] = sorted[j--];
        }
    }
};