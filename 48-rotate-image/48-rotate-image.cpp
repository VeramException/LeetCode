class Solution 
{
    public:
    
    void rotate(vector<vector<int> > &matrix)
    {
        reverse(matrix.begin(), matrix.end());

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int r=0; r<rows; r++)
            for (int c=r; c<cols; c++)
                swap(matrix[r][c], matrix[c][r]);
    }
    
};


/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/