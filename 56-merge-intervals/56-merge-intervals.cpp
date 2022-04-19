class Solution
{
    public:
    static bool customSort(vector<int> a, vector<int> b)
    {
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        
        // Sort by first value
        sort(intervals.begin(), intervals.end(), customSort);
        
        res.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); ++i)
        {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            else
                res.push_back(intervals[i]);
        }
        
        return res;
    }
};