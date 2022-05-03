// Do Top-Down with cache ==> Memoization
// Bottom-Up i.e., DP can be really dificult to come up in interview.

class Solution
{
public:
    string s;
    string p;
    unordered_map<int, unordered_map<int, bool>> cache;
    
    bool isMatch(string ss, string pp)
    {
        s = ss;
        p = pp;
        
        // Top-Down - Memoization.
        return dfs (0, 0);        
    }
    
    bool dfs(int i, int j)
    {
        if (i >= s.size() && j >= p.size())
            return true;
        
        if (j >= p.size())
            return false;
        
        bool match = (i < s.size() && j < p.size() &&  (s[i] == p[j] || p[j] == '.'));
        
        if (j+1 < p.size() && p[j+1] == '*')
        {
            return dfs (i, j+2) || (match && dfs (i+1, j));
        }
        
        if (match)
            return dfs (i+1, j+1);
        
        return false;
    }
};
