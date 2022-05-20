class Solution 
{
    
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& grid)
    {        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> result;
        for (int s=0; s<=(rows+cols-2); s++)
        {
            // for all   ..... r + c = s
            for (int x=0; x<=s; x++)
            {
                int r = x;
                int c = s-r;
               
                if (s%2 == 0) //even
                    swap(r, c);
  
                if (r >= rows || c >= cols)
                    continue;
                
                result.push_back(grid[r][c]);
            }
        }
        return result;
    }
};