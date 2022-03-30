class Solution
{
    public:
    int rows;
    int cols;
    
    int getVal(vector<vector<int>>& matrix, int index)
    {
        int r = index/cols;
        int c = index%cols;
        
        return matrix[r][c];
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        rows = matrix.size();
        cols = matrix[0].size();
        
        int lo = 0;
        int hi = rows*cols -1;
        
        while (lo <= hi)
        {
            int mid = (lo+hi)/2;
            
            int midVal = getVal(matrix, mid);
                
            if (midVal == target)
                return true;
            
            if (target < midVal)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return false;
    }
};