// Core logic:
// At every iteration, increment the smallest number in the array by '1',
// then the product will be maximum for that iteration
// If we have 'k' increments to do, we just have to do the same thing for 'k' iterations.
// i.e., find the smallest at every iteration and increment it by '1'

class Solution
{
    public:
    int maximumProduct(vector<int>& nums, int k)
    {
        priority_queue <int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); // minHeap
        
        while (k > 0)
        {
            int x = pq.top(); pq.pop();
            pq.push(x+1);
            k--;
        }
        
        long long res = 1;
        int mod = pow(10,9)+7;
        while (!pq.empty())
        {
            int x = pq.top();
            res = (res * x) % mod;
            pq.pop();
        }
        return res;
    }
};