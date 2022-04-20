class Solution
{
    public:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> completed;
    unordered_set<int> currentPath;
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
        if (completed.count(course) > 0)
            return true;
        
        // we already found this in current path - i.e., a cycle is formed
        if (currentPath.count(course) > 0)
            return false;
        
        currentPath.insert(course);
        
        for (int p: adjList[course])
            if (dfs(p) == false)
                return false;
        
        // remove this course from current path
        currentPath.erase(currentPath.find(course));
        
        res.push_back(course);
        completed.insert(course);
        
        return true;
    }
};