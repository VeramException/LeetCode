class Solution
{
    public:
    int maximumProduct(vector<int>& nums, int k)
    {
        priority_queue <int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        
        while (k > 0)
        {
            int x = minHeap.top(); minHeap.pop();
            minHeap.push(x+1);
            k--;
        }
        
        long long res = 1;
        int mod = pow(10,9)+7;
        while (!minHeap.empty())
        {
            int x = minHeap.top();
            res = (res * x) % mod;
            minHeap.pop();
        }
        return res;
    }
};