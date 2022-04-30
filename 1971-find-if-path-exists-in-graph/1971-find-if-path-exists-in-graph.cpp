class Solution
{
    public:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        if (source == destination)
            return true;
        
        for (vector<int>& edge: edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        return dfs(source, destination);
    }
    
    bool dfs(int node, int destination)
    {
        if (visited.count(node))
            return false;
        
        visited.insert(node);
        
        for (int n: adjList[node])
        {
            if (n == destination)
                return true;
            
            if (dfs(n, destination))
                return true;
        }
        
        return false;
    }
};