class Solution
{
    public:
    int rows, cols;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid[0][0] == 1)
            return -1;
        
        rows = grid.size();
        cols = grid[0].size();
        
        queue<vector<int>> q;
        q.push({0,0,1}); // {r, c, distance}
        grid[0][0] = 1;  // mark as visited
        
        while (!q.empty())
        {
            int qSiz = q.size();
            while (qSiz-- > 0)
            {
                vector<int> cell = q.front(); q.pop();
                if (cell[0] == rows-1 && cell[1] == cols-1)
                    return cell[2];
                
                for (vector<int> d: directions)
                {
                    int r = cell[0]+d[0];
                    int c = cell[1]+d[1];
                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 0)
                        continue;
                    
                    q.push({r, c, cell[2]+1});
                    grid[r][c] = 1;             // mark as visited
                }
                    
            }
        }
        
        return -1;
    }
};