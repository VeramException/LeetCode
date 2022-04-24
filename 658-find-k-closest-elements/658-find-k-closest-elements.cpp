class Solution
{
    public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x)
    {
        priority_queue<pair<int, int>> pq;        
        for (int num: nums)
        {
            if (pq.size() < k)
                pq.push({abs(num-x), num});
            else
            {
                if (abs(num-x) < abs(pq.top().first))
                {
                    pq.pop();
                    pq.push({abs(num-x), num});
                }
            }
        }
        
        multiset<int> s;
        while (!pq.empty())
        {
            s.insert(pq.top().second);
            pq.pop();
        }
        return vector<int>(s.begin(), s.end());
    }
};