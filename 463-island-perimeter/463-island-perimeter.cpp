//
// Iteration-2
//
class Solution
{
    public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int perimeter = 0;
        int left, right, top, bottom;
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
            {
                if (grid[r][c] == 1)
                {
                    left   = (c == 0      || grid[r][c-1] == 0)? 1: 0;
                    right  = (c == cols-1 || grid[r][c+1] == 0)? 1: 0;
                    top    = (r == 0      || grid[r-1][c] == 0)? 1: 0;
                    bottom = (r == rows-1 || grid[r+1][c] == 0)? 1: 0;
                    
                    perimeter += left+right+top+bottom;
                }
            }
        }
        return perimeter;
    }
};