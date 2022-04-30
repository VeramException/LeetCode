class Solution 
{
    public:
int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();

        int mindist = INT_MAX;
        vector<vector<int>> distance(m, vector<int>(n,0));
        
        int target = 0;
        
        vector<vector<int>> dir {{1,0},{0,1}, {-1,0},{0,-1}};
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 1) continue;
                
                mindist = INT_MAX;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                int level = 1;
                while(!q.empty())
                {
                    int sz = q.size();
                    for(int k = 0; k < sz; k++)
                    {
                        auto curr = q.front();
                        q.pop();
                        for(auto &d : dir)
                        {
                            int a = curr.first+d[0];
                            int b = curr.second+d[1];
                            
                            if(a == m || b == n || a == -1 || b == -1) continue;
                            
                            if(grid[a][b] == target)
                            {
                                q.emplace(a,b);
                                grid[a][b]--;
                                distance[a][b] += level;
                                mindist = min(mindist, distance[a][b]);
                            }
                        }
                    }
                    level++;
                }
                target--;
            }
        }
        
        return mindist == INT_MAX ? -1 : mindist;
        
    }
};