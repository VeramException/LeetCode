class Solution
{
    public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        int maxLen = 0;
        for (int i=m-1; i>=0; i--)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    maxLen = max(maxLen, dp[i][j]);
                }
                // if the question is not substring, but subsequence
                // else
                // {
                //     DP[i][j] = max(DP[i+1][j], DP[i][j+1]);
                // }
            }
        }
        return maxLen;
    }
};