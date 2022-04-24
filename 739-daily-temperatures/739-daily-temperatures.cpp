class Solution
{
    public:
    vector<int> dailyTemperatures(vector<int>& nums)
    {
        int n = nums.size();
        stack<pair<int, int>> s;
        
        vector<int> res(n);
        for (int i=0; i<n; i++)
        {
            while (s.size() > 0 && s.top().first < nums[i])
            {
                res[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.push({nums[i], i});
        }
        
        return res;
    }
};