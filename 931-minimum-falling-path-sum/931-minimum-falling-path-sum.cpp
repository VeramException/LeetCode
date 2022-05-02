class Solution
{
    public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int r=1; r<rows; r++)
            for (int c=0; c<cols; c++)
                matrix[r][c] += min ({ matrix[r-1][max(0, c-1)], 
                                       matrix[r-1][c], 
                                       matrix[r-1][min(cols-1 ,c+1)] });
        
        return *min_element(matrix[rows-1].begin(), matrix[rows-1].end());
    }
};