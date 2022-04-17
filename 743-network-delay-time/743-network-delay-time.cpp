class Solution
{
    public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // 1) Adjacency List
        unordered_map<int, vector<vector<int>>> adjList;
        for (vector<int> time: times)
            adjList[time[0]].push_back({time[1], time[2]});
        
        // 2) Min-heap  <cost, node>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k}); // cost = 0, starting node = k
        
        // 3) Visited
        unordered_set<int> visited;
        
        int totalCost = 0;
        while (!pq.empty())
        {
            int w1 = pq.top()[0];
            int n1 = pq.top()[1]; pq.pop();
            
            if (visited.count(n1))
                continue;
            visited.insert(n1);
            
            totalCost = max(totalCost, w1);
            for (vector<int> e: adjList[n1])
            {
                int n2 = e[0];
                int w2 = e[1];
                if (!visited.count(n2))
                    pq.push({w1+w2, n2});
            }
        }
        
        return (visited.size() == n)? totalCost: -1;
    }
};