class Solution
{
    public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // After rows*cols shifts, the result grid will be same as original input grid.
        if (k >= rows*cols)
            k = k % (rows*cols);
        
        if (k == 0)
            return grid;
        
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                int linearIndex    = r*cols + c;
                int newLinearIndex = (linearIndex + k)%(rows*cols);
                
                int rr = newLinearIndex/cols;
                int cc = newLinearIndex%cols;
                
                res[rr][cc] = grid[r][c];
            }
        }
        return res;
    }
};