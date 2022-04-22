//
// Greedy solution
//

class Solution
{
    public:
    bool isMatch(string s, string p)
    {
        int match;
        int lastStar = -1;
        
        int i = 0;
        int j = 0;
        while (i < s.size())
        {
            if (j < p.size() && 
                (s[i] == p[j] || p[j] == '?'))
            {
                i++;
                j++;
            }
            else if (j < p.size() && p[j] == '*')
            {
                match = i;
                lastStar = j;
                j++;
            }
            else if (lastStar >= 0)
            {
                match++;
                i = match;
                j = lastStar+1;
            }
            else
                return false;
        }
        
        while (j < p.size() && p[j] == '*') j++;
        
        return (j == p.size());
    }
};