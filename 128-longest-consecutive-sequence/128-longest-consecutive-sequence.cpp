class Solution
{
    public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        for (int num: nums)
            s.insert(num);
        
        int res = 0;
        for (int num: nums)
        {
            if (s.count(num-1) == 0)
            {
                int currMaxLength = 0;
                while (s.count(num++) > 0)
                {
                    currMaxLength++;
                    res = max(res, currMaxLength);
                }
            }
        }
        return res;
    }
};