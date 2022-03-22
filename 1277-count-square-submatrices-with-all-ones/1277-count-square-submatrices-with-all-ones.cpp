// Same questions:
// LC 1277: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// LC 221: https://leetcode.com/problems/maximal-square/


class Solution
{
    public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        int count = 0;
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                if (matrix[r][c] == 1)
                {
                    if (r > 0 && c > 0)
                        dp[r][c] += min ({dp[r-1][c], dp[r][c-1], dp[r-1][c-1]}) + 1;
                    else
                        dp[r][c] = 1;
                }
                count += dp[r][c];
            }
        }
        
        return count;
    }
};