class Solution
{
    public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // -- Optimization -- (Edge case)
        // After rows*cols shifts, the result grid will be same as original input grid.
        if (k % (rows*cols) == 0)
            return grid;
        
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                int oldlinearIndex    = r*cols + c;
                int newLinearIndex = (oldlinearIndex + k)%(rows*cols); // %(rows*cols) is important optimization.
                
                int rr = newLinearIndex/cols;
                int cc = newLinearIndex%cols;
                
                res[rr][cc] = grid[r][c];
            }
        }
        return res;
    }
};