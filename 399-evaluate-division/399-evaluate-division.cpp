class Solution
{
    public:
    unordered_map<string, vector<pair<string, double>>> adjList;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        
        vector<double> res;
        for (auto q: queries)
        {
            unordered_set<string> visited;
            
            if (q[0] == q[1] && adjList.count(q[0]) > 0)
                res.push_back(1.0);
            else
            {
                pair<bool, double> result = dfs(q[0], q[1], visited, 1.0);
                res.push_back(result.second);
            }
        }
        return res;
    }
    
    // searches path from 'a' to 'b' while multiplying all weights in between
    pair<bool, double> dfs (string a, string b, unordered_set<string>& visited, double val)
    {
        if (visited.count(a) == 1)
            return {false, -1.0};
            
        visited.insert(a);
        
        for (pair<string, double> node: adjList[a])
        {
            double temp = val * node.second;
            if (node.first == b)
                return {true, temp};
            
            pair<bool, double> result = dfs(node.first, b, visited, temp);
            if (result.first == true)
                return result;
        }
        
        return {false, -1.0};
    }
};