// Same questions:
// LC 1277: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// LC 221: https://leetcode.com/problems/maximal-square/

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int largestMatrixSize = 0;

        // Build the DP matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i > 0 && j > 0)
                        dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j] }) + 1;
                    else
                        dp[i][j] = 1;
                }
                largestMatrixSize = (largestMatrixSize < dp[i][j]) ? dp[i][j] : largestMatrixSize;
            }
        }
        return largestMatrixSize * largestMatrixSize;
    }
};