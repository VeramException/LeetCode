class Solution
{
    public:
    
    int rows, cols;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int minimumEffortPath(vector<vector<int>>& heights)
    {        
        rows = heights.size();
        cols = heights[0].size();
        
        if (rows == 1 && cols == 1)
            return 0;

        vector<vector<int>> minEffort(rows, vector<int>(cols, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {distance}
        pq.push({0, 0, 0});  // {effort, r, c}
        minEffort[0][0] = 0;
        
        while (!pq.empty())
        {
            int d = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            
            for (vector<int>& dir: directions)
            {
                int rr = r + dir[0];
                int cc = c + dir[1];
                
                //if(rr == rows-1 && cc == cols-1) 
//                    return d;
                
                if (rr >= 0 && rr < rows && cc >= 0 && cc < cols)
                {
                    int a = heights[r][c];
                    int b = heights[rr][cc];
                    
                    int effort = max(d, abs(a - b));
                    
                    if (minEffort[rr][cc] > effort)  // better path
                    {
                        minEffort[rr][cc] = effort;
                        pq.push({effort, rr, cc});
                    }
                }
            }
        }        
        
        return minEffort[rows-1][cols-1];
    }
};