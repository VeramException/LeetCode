class Solution
{
    public:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
    unordered_set<int> cycle;
    vector<int> res;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        // Put every course on adjacency list
        for (int i=0; i<numCourses; i++)
            adjList[i] = {};
        
        // add all prereqs to the adjacency list map
        for (vector<int> p: prerequisites)
            adjList[p[0]].push_back(p[1]);
        
        for (int i=0; i<numCourses; i++)
            if (dfs(i) == false)
                return {};
        
        return res;
    }
    
    bool dfs(int course)
    {
        if (cycle.count(course) > 0)
            return false;
        
        // we can return from here, we can go through this again
        if (visited.count(course) > 0)
            return true;
        
        cycle.insert(course);
        
        for (int p: adjList[course])
            if (dfs(p) == false)
                return false;
        
        // remove this course from cycle
        cycle.erase(cycle.find(course));
        
        visited.insert(course);
        
        res.push_back(course);
        return true;
    }
};