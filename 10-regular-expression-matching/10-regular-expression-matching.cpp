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
        if (cache.count(i) && cache[i].count(j))
            return cache[i][j];
        
        if (i >= s.size() && j >= p.size())
            return true;
        
        if (j >= p.size())
            return false;
        
        bool match = (i < s.size() && j < p.size() && 
                     (s[i] == p[j] || p[j] == '.'));
        
        if ((j + 1) < p.size() && p[j+1] == '*')
        {
            cache[i][j] = dfs(i, j+2) ||          // Don't consider the <char>* which means we took "0" matching elements in 's'
                          (match && dfs(i+1, j)); // We considered 1 match for now for <char>*, but for this there should be a match in 's'
            
            return cache[i][j];;
        }
        
        if (match)
        {
            cache[i][j] = dfs(i+1, j+1);
            return cache[i][j];
        }
        
        return false;
    }
};
