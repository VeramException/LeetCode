class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m; // <char, index>
        
        int l=0, r=0, maxLength=0;
        while (r < s.size())
        {
            if (m.count(s[r]) == 1)
            {
                while (l <= m[s[r]])
                    m.erase(m.find(s[l++]));
            }
            m[s[r]] = r;
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        
        return maxLength;
    }
};