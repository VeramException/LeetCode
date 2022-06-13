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
                
                if (i == n-1)
                    res = min (res, triangle[i][j]);
            }
        }
        
        return (n == 1)? triangle[0][0]: res;
    }
};