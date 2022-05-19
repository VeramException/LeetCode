class Solution
{
    private:
    int rows, cols;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    
    public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        rows = matrix.size();
        cols = matrix[0].size();
        
        vector<vector<int>> DP(rows, vector<int>(cols, 0));
        
        int res = 0;
        for (int r=0; r<rows; r++)
            for (int c=0; c<cols; c++)
                res = max(res, findLongestPath(matrix, DP, r, c));
        return res;
    }
    
    int findLongestPath(vector<vector<int>>& matrix, vector<vector<int>>& DP, int r, int c)
    {
        if (DP[r][c] != 0)
            return DP[r][c];
        
        for (vector<int>& d: directions)
        {
            int rr = r + d[0];
            int cc = c + d[1];
            
            if (rr < 0 || rr >= rows || cc < 0 || cc >= cols || matrix[rr][cc] <= matrix[r][c])
                continue;
            
            DP[r][c] = max(DP[r][c], findLongestPath(matrix, DP, rr, cc));
        }
        
        return ++DP[r][c];
    }
};