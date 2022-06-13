class Solution
{
    public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n=triangle.size(), res = INT_MAX;
        for (int i=1; i<n; i++)
        {
            int m = triangle[i].size();
            for (int j=0; j<m; j++)
            {
                triangle[i][j] += min(triangle[i-1][max(0, j-1)], 
                                      triangle[i-1][min(m-2, j)]);                
                res = (i == n-1)? min (res, triangle[i][j]): INT_MAX;
            }
        }        
        return (n == 1)? triangle[0][0]: res;
    }
};