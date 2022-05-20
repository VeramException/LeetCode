class Solution
{    
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> DP(rows+1, vector<int>(cols+1, 0));
        
        DP[0][1] = 1;  // to reach to grid[0][0], either DP[0][1] or DP[1][0] has to be '1'.
        
        for (int r=1; r<rows+1; r++)
        {
            for (int c=1; c<cols+1; c++)
            {
                if (grid[r-1][c-1] == 0)
                    DP[r][c] = DP[r-1][c] + DP[r][c-1];
            }
        }
        
        return DP[rows][cols];
    }
};