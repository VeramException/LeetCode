class Solution
{
    public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int minimumEffortPath(vector<vector<int>>& heights)
    {        
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));
        minEffort[0][0] = 0;
        
        queue<vector<int>> q;
        q.push({0, 0});        
        
        while (!q.empty())
        {
            int r = q.front()[0];
            int c = q.front()[1];
            q.pop();
            
            for (vector<int>& dir: directions)
            {
                int rr = r + dir[0];
                int cc = c + dir[1];
                
                if (rr >= 0 && rr < rows && cc >= 0 && cc < cols)
                {
                    int a = heights[r][c];   // current cell
                    int b = heights[rr][cc]; // next cell
                    
                    int effort = max(minEffort[r][c], abs(a - b)); // maximum of
                                                                   // effort needed to reach from [0,0] to current cell
                                                                   // or
                                                                   // effort needed to climb to next cell
                    
                    if (minEffort[rr][cc] > effort)  // we found better path (path that takes less effort)
                    {
                        minEffort[rr][cc] = effort;
                        q.push({rr, cc});
                    }
                }
            }
        }        
        
        return minEffort[rows-1][cols-1];
    }
};