class Solution
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m; // <char, index>
        
        int l = 0;
        int r = 0;
        int maxLength = 0;
        while (r < s.size())
        {
            int value = s[r];
            if (m.count(value) > 0)
            {
                while (l <= m[value])
                    m.erase(m.find(s[l++]));
            }
            
            maxLength = max(maxLength, r-l+1);
            m[value] = r;
            r++;
        }
        
        return maxLength;
    }
};