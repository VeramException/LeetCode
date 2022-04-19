class Solution
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        map<int, int> m;
        for (vector<int> interval: intervals)
        {
            m[interval[0]]++;
            m[interval[1]]--;
        }
        
        int res = 0;
        int cur = 0;
        for (auto const& [k,v]: m)
        {
            cur = cur + v;
            res = max(res, cur);
        }
        return res;
    }
};