class Solution
{
    public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> maxHeap (stones.begin(), stones.end());
        
        while (maxHeap.size() > 1)
        {
            int l = maxHeap.top(); maxHeap.pop();
            int r = maxHeap.top(); maxHeap.pop();            
            if (l != r) maxHeap.push(abs(l-r));
        }
        
        return maxHeap.empty()? 0: maxHeap.top();
    }
};