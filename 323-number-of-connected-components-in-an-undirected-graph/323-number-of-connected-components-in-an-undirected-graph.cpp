// Union-Find

class Solution
{
    public:
    vector<int> parent;   // {0, 1, 2, 3, 4, 5, ....... n}
    vector<int> rank;     // {1, 1, 1, 1, 1, 1, ........1}
    int countComponents(int n, vector<vector<int>>& edges)
    {   
        // Initialize parent & rank.
        for (int i=0; i<n; i++)
        {
            parent.push_back(i);
            rank.push_back(1);
        }
        
        int res = n;
        for (auto edge: edges)
            res = res - unions(edge[0], edge[1]);
        return res;
    }
    
    int find(int x)
    {
        int res = x;
        while (res != parent[res])
        {
            parent[res] = parent[parent[res]];   // Optimization: compression
            res = parent[res];
        }
        return res;
    }
    
    int unions(int x1, int x2)
    {
        int p1 = find(x1);        // find the top-most parent of x1
        int p2 = find(x2);        // find the top-most parent of x2
        
        if (p1 == p2)             // if both have same parent, nothing needs to be done.
            return 0;
        
        if (rank[p2] > rank[p1])  // if p2 have more children than p1, add p1 as child to p2 (to not increase tree height)
        {
            parent[p1] = p2;
            rank[p2] += rank[p1]; 
        }
        else                      // else, do the oppposite
        {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }        
        return 1;
    }
};