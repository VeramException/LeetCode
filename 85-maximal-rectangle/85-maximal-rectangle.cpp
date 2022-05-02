class Solution
{
    public:
    int maximalRectangle(vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> heights(cols, 0);
        
        int maxRectangleArea = 0;
        for (int r=0; r<rows; r++)
        {
            for (int c=0; c<cols; c++)
                heights[c] = (grid[r][c] == '1')? (heights[c]+1): 0;

            int currMaxHeight = largestRectangleArea(heights);
            maxRectangleArea = max (maxRectangleArea, currMaxHeight);
        }
        return maxRectangleArea;
    }
    
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> s;  // Important: stack<index>, not stack<height>
        int maxArea = 0;
        
        for (int i=0; i<=heights.size(); i++)
        {
            int currHeight = (i == heights.size())? 0: heights[i]; // if we reached end of array, we take currHeight = 0;
            
            while (!s.empty() && currHeight < heights[s.top()])
            {
                int topIndex = s.top(); s.pop();
                
                int width = s.empty()? (i-0): (i-s.top()-1);
                int area = heights[topIndex]*width;
                
                maxArea = max(maxArea, area);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};