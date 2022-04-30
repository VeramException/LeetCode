class Solution 
{
    public:
    
    void rotateFrame(vector<vector<int>>& matrix, int startIndex)
    {
        int i = startIndex;
        int j = (matrix.size() - startIndex) - 1;
        int n = matrix.size()-1;
        while (i < j)
        {
            int temp = matrix[startIndex][i];
            swap(temp, matrix[i][j]);
            swap(temp, matrix[j][n-i]);
            swap(temp, matrix[n-i][startIndex]);
            swap(temp, matrix[startIndex][i]);
            i++;
        }
    }
    
    void rotate(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < (matrix.size() / 2); i++)
            rotateFrame(matrix, i);
    }
    
};