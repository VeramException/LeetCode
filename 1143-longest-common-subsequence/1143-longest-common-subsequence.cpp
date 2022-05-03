class Solution
{
    public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
        
        for (int i=m-1; i>=0; i--)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (text1[i] == text2[j])
                    DP[i][j] = 1+DP[i+1][j+1];
                else
                    DP[i][j] = max(DP[i+1][j], DP[i][j+1]);
            }
        }
        
        return DP[0][0];
    }
};