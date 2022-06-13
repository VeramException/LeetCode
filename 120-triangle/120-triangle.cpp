class Solution
{
    public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n=triangle.size(), res = INT_MAX;
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<triangle[i].size(); j++)
            {
                if (j == 0)
                    triangle[i][0] += triangle[i-1][0];
                else if (j == triangle[i].size()-1)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                
                if (i == n-1)
                    res = min (res, triangle[i][j]);
            }
        }
        
        return (n == 1)? triangle[0][0]: res;
    }
};