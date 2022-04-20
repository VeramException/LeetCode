class Solution
{
    public:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // Build adjacency list
        for (vector<int> p: prerequisites)
            adjList[p[0]].push_back(p[1]);
        
        for (auto const& [k, v]: adjList)
            if(dfs(k) == false)
                return false;

        return true;
    }
    
    bool dfs(int course)
    {
        if (adjList[course].size() == 0)
            return true;
            
        if (visited.count(course))
            return false;
        
        visited.insert(course);
        
        for (int c: adjList[course])
            if(dfs(c) == false)
                return false;
        
        adjList[course] = {};
        
        return true;
    }
};