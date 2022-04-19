class Solution
{
    public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int N = nums.size();
        vector<int> res(N, 1);
        
        int leftProduct = 1;
        for (int i=1; i<N; i++)
        {
            leftProduct = leftProduct * nums[i-1];
            res[i] = res[i] * leftProduct;
        }
        
        int rightProduct = 1;
        for (int i=N-2; i>=0; i--)
        {
            rightProduct = rightProduct * nums[i+1];
            res[i] = res[i] * rightProduct;
        }
        
        return res;
    }
};
/*
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
*/