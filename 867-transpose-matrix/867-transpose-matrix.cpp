class Solution
{
    public:
    vector<vector<int>> transpose(vector<vector<int>> matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> res(cols, vector<int>(rows, 0));
        
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                res[c][r] = matrix[r][c];
        
        return res;
    }
};