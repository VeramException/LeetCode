class Solution
{
public:
    int rows, cols;

    int countServers(vector<vector<int>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();

        int connectedServers = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    int currentConnected = 1;
                    dfs(grid, r, c, currentConnected);

                    if (currentConnected > 1)
                        connectedServers += currentConnected;
                }
            }
        }
        return connectedServers;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& currConnected)
    {
        vector<vector<int>> directions = { {1,0}, {0,1}, {-1,0}, {0,-1} };
        for (vector<int> d : directions)
        {
            int rr = r + d[0];
            int cc = c + d[1];
            while (rr >= 0 && rr < rows && cc >= 0 && cc < cols && grid[rr][cc] == 0)
            {
                rr += d[0];
                cc += d[1];
            }

            if (rr >= 0 && rr < rows && cc >= 0 && cc < cols && grid[rr][cc] == 1)
            {
                grid[rr][cc] = 2;
                dfs(grid, rr, cc, ++currConnected);
            }
        }
    }
};