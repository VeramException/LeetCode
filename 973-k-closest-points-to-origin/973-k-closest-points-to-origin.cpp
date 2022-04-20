class Solution
{
    public:
    struct customCompare
    {
        bool operator()(vector<int> a, vector<int> b)
        {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, customCompare> pq;
        
        for (vector<int>& p: points)
        {
            pq.push(p);
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};