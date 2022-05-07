class Solution
{
    public:
    
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        for (int r=0; r<m; r++)
            for (int c=0; c<n; c++)
                if (grid[r][c] == 1)
                    row[r]++, col[c]++;
        
        int total = 0;
        for (int r=0; r<m; r++)
            for (int c=0; c<n; c++)
                if (grid[r][c] == 1 && (row[r] >= 2 || col[c] >= 2))
                    total++;
        
        return total;
    }
};