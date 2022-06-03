class NumMatrix
{
    public:
    vector<vector<int>> grid;
    
    NumMatrix(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        grid.resize(rows+1, vector<int>(cols+1, 0));
        
        for (int r=1; r<=rows; r++)
        {
            int runSum = 0;
            for (int c=1; c<=cols; c++)
            {
                runSum += matrix[r-1][c-1];
                grid[r][c] =  runSum + grid[r-1][c];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2)
    {
        return grid[r2+1][c2+1] - grid[r2+1][c1] - grid[r1][c2+1] + grid[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */