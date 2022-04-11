class Solution
{
    public:
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    k = k % (m*n);
    while(k--)
    {
       for(int i=0;i<m;++i)
            for(int j=n-2;j>=0;--j)
                swap(grid[i][j],grid[i][j+1]);

       for(int i=m-2;i>=0;--i)
            swap(grid[i][0],grid[i+1][0]);
    }
    return grid;
}
};