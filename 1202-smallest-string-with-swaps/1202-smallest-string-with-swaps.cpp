class Solution
{
    private:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;

    vector<int> connectedIndices;
    string connectedIndicesString;
    
    public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {        
        for (vector<int> pair: pairs)
        {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }
        
        for (int i=0; i<s.size(); i++)
        {
            if(!visited.count(i))
            {
                connectedIndicesString = "";
                connectedIndices.clear();
                
                dfs(s, i);
                
                // Eg: "dcab", [[0,3],[1,2],[0,2]]  ==> adjList[0] = {3,2}
                //                                      adjList[1] = {2}
                //                                      adjList[2] = {1,0}
                //                                      adjList[3] = {0}
                
                sort(connectedIndicesString.begin(), connectedIndicesString.end()); // dbac --> abcd
                sort(connectedIndices.begin(), connectedIndices.end());             // 0,3,2,1 ---> 0,1,2,3
                
                for (int i=0; i<connectedIndices.size(); i++)
                    s[connectedIndices[i]] = connectedIndicesString[i];
            }
        }
        
        return s;
    }
    
    void dfs(string& s, int i)
    {
        if (visited.count(i))
            return;
        
        visited.insert(i);
        connectedIndices.push_back(i);
        connectedIndicesString += s[i];
        
        for (int j: adjList[i])
            dfs(s, j);
    }
};