class Solution
{
    public:
    int missingNumber(vector<int>& nums)
    {
        int i = 1;
        int res = 0;
        
        for (int num: nums)
        {
            res = res ^ num;
            res = res ^ i;
            i++;
        }
        
        return res;
    }
};