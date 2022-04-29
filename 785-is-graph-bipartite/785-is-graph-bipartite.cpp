class Solution
{
    public:
    vector<int> colors;
    
    bool isBipartite(vector<vector<int>>& graph)
    {
        //  0 --> Not coded
        //  1 --> group A
        // -1 --> group B
        colors.resize(graph.size(), 0);
        
        for (int i=0; i<graph.size(); i++)
            if (colors[i] == 0 && !isValidColorDfs(graph, 1, i))
                return false;
        
        return true;
    }
    
    bool isValidColorDfs(vector<vector<int>>& graph, int color, int node)
    {
        if (colors[node] != 0)
            return colors[node] == color;
        
        colors[node] = color;
        for (int j: graph[node])
            if (!isValidColorDfs(graph, -color, j))
                return false;
        
        return true;
    }
};