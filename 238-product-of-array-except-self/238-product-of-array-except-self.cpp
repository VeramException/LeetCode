class Solution
{
    public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int N = nums.size();
        vector<int> lp(N, 1);
        vector<int> rp(N, 1);
        
        for (int i=1; i<N; i++)
            lp[i] = lp[i-1] * nums[i-1];
        
        for (int i=N-2; i>=0; i--)
            rp[i] = rp[i+1] * nums[i+1];

        for (int i=0; i<N; i++)
            rp[i] = rp[i] * lp[i];
        
        return rp;
    }
};