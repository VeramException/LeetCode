class Solution
{
    public:
    int rows, cols;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int shortestDistance(vector<vector<int>>& grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        
        vector<vector<int>> distance(rows, vector<int> (cols, 0));
        
        int minDist = INT_MAX;
        int target = 0;        // Instead of looking for '0', let's look for target.
                               // For each building, we can mark them as target-1 to track visited
        
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                // Find shortest distance of each empty space to this building (i.e., '1')
                if (grid[r][c] == 1)
                {                    
                    int level = 1;
                    minDist = INT_MAX;
                    
                    queue<pair<int, int>> q;
                    q.push({r,c});
                    
                    while (!q.empty())
                    {
                        int siz = q.size();
                        while (siz-- > 0)
                        {
                            auto curr = q.front(); q.pop();
                            for (vector<int>& d: directions)
                            {
                                int rr = curr.first  + d[0];
                                int cc = curr.second + d[1];
                                
                                if (!(rr >= 0 && cc >=0 && rr < rows && cc < cols))
                                    continue;
                                
                                if (grid[rr][cc] == target)
                                {
                                    q.push({rr,cc});
                                    grid[rr][cc]--;
                                    distance[rr][cc] += level;
                                    minDist = min(minDist, distance[rr][cc]);
                                }
                            }
                        }
                        level++;
                    }
                    // At this point, we might have marked all the visited 0's as -1.
                    // So, for next iteration, we need to look for -1s
                    target--;
                }
            }
        }
        
        return (minDist == INT_MAX)? -1: minDist;
    }
};
