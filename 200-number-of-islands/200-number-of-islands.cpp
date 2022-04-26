class Solution
{
    public:
    int rows, cols;
    int islands;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int numIslands(vector<vector<char>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();
    
        islands = 0;
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r,c);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (grid[r][c] != '1')
            return;
        
        grid[r][c] = '2';
        for (auto d: directions)
        {
            int rr = r + d[0];
            int cc = c + d[1];
            
            if (rr>=0 && rr<rows && cc>=0 && cc<cols && grid[rr][cc] == '1')
                dfs(grid, rr, cc);
        }
    }
};