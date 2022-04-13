class Solution
{
    public:
    int rows, cols;
    
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 1)
            return matrix[0];
        
        rows = matrix.size();
        cols = matrix[0].size();
        
        vector<int> res;
        int startIndex = 0;
        while (res.size() < rows*cols)
            loadFrame(matrix, startIndex++, res);

        return res;
    }
    
    void loadFrame(vector<vector<int>>& matrix, int si, vector<int>& res)
    {
        // si = start index
        
        // Edge Case - 1: Only one element remaining
        if (res.size() == (rows*cols)-1)
            res.push_back(matrix[si][si]);
        
        // Left to Right
        // [si,si] -> [si, cols-si-1]
        int r = si;
        int c = si;
        while (c < cols-si-1 && res.size() < rows*cols) // Edge case -2: Add "res.size() < rows*cols" in all while loops
            res.push_back(matrix[r][c++]);
        
        // Top to Bottom
        r = si;
        c = cols-si-1;
        while (r < rows-si-1 && res.size() < rows*cols)
            res.push_back(matrix[r++][c]);
        
        // Right to Left
        r = rows-si-1;
        c = cols-si-1;
        while (c >= si+1 && res.size() < rows*cols)
            res.push_back(matrix[r][c--]);
        
        // Bottom to Right
        r = rows-si-1;
        c = si;
        while (r >= si+1 && res.size() < rows*cols)
            res.push_back(matrix[r--][c]);
    }
};