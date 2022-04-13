class Solution
{
    public:
    int rows, cols, count = 0;
    
    vector<vector<int>> generateMatrix(int n)
    {
        rows = n, cols = n;
        
        int startIndex = 0;
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        
        while (count < rows*cols)
            loadFrame(res, startIndex++);
        
        return res;
    }
    
    void loadFrame(vector<vector<int>>& res, int si)
    {
        // si = start index
        
        // Edge Case - 1: Only one element remaining
        if (count == (rows*cols)-1)
            res[si][si] = ++count;
        
        // Left to Right
        // [si,si] -> [si, cols-si-1]
        int r = si;
        int c = si;
        while (c < cols-si-1 && count < rows*cols) // Edge case -2: Add "count < rows*cols" in all while loops
            res[r][c++] = ++count;
        
        // Top to Bottom
        r = si;
        c = cols-si-1;
        while (r < rows-si-1 && count < rows*cols)
            res[r++][c] = ++count;
        
        // Right to Left
        r = rows-si-1;
        c = cols-si-1;
        while (c >= si+1 && count < rows*cols)
            res[r][c--] = ++count;
        
        // Bottom to Right
        r = rows-si-1;
        c = si;
        while (r >= si+1 && count < rows*cols)
            res[r--][c] = ++count;
    }
};