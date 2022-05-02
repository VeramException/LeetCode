class Solution
{
    public:
    long long maxPoints(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<long long> prevRow (cols, 0);
        vector<long long> currRow (cols, 0);
        
        for (int r=0; r<rows; r++)
        {
            // Left ---> Right
            long long leftRunMax = 0;
            for (int c=0; c<cols; c++)
            {
                leftRunMax = max (prevRow[c], leftRunMax-1);
                currRow[c] = leftRunMax;
            }
            
            // left <--- Right
            long long rightRunMax = 0;
            for (int c=cols-1; c>=0; c--)
            {
                rightRunMax = max (prevRow[c], rightRunMax-1);
                currRow[c] = max (rightRunMax, currRow[c]) + grid[r][c];
            }
            
            swap(prevRow, currRow);
        }
        
        // Why prevRow and not currRow, because at this point, we have already swapped prevRow & currRow
        return *max_element(prevRow.begin(), prevRow.end());
    }
};