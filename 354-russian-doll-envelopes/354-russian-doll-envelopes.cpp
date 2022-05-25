class Solution
{
    public:
   
    bool static customCompare (vector<int>& a, vector<int>& b) 
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& nums)
    {
        sort(nums.begin(), nums.end(), customCompare);

        vector<int> DP;
        
        for (auto& num: nums)
        {
            auto iter = lower_bound(DP.begin(), DP.end(), num[1]);
            if (iter == DP.end())
                DP.push_back(num[1]);
            else
                *iter = num[1];
        }
        return DP.size();
    }
};