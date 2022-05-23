class Solution
{
    public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> DP(m+1, vector<int> (n+1, 0));
        
        for (string s: strs)
        {
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size()-ones;
            
            for (int i=m; i>=zeros; i--)
            {
                for (int j=n; j>=ones; j--)
                {
                    DP[i][j] = max (DP[i][j], 1 + DP[i-zeros][j-ones]);
                }
            }
        }
        
        return DP[m][n];
    }
};


