class Solution
{
    public:
    priority_queue<pair<int,int>> maxHeap; // count, index
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        int N = mat[0].size();
        for (int i=0; i<mat.size(); i++)
        {
            int count = getCount(mat[i]);
            
            if (maxHeap.size() < k)
                maxHeap.push({count, i});
            else if (maxHeap.top().first > count
                     || maxHeap.top().first == count && maxHeap.top().second > i)
            {
                maxHeap.pop();
                maxHeap.push({count, i});
            }
        }
        
        vector<int> res(maxHeap.size());
        int i = maxHeap.size()-1;
        while (maxHeap.size()>0)
        {
            res[i--] = maxHeap.top().second;
            maxHeap.pop();
        }
        return res;
    }
    
    int getCount(vector<int> &nums)
    {
        int lo = 0;
        int hi = nums.size()-1;
        
        if (nums[lo] == 0)
            return 0;
        if (nums[hi] == 1)
            return hi+1;        
        
        while (lo < hi)
        {
            int mid = (lo+hi)/2;
            if (nums[mid] == 0)
                hi = mid;
            else
                lo = mid+1;
        }
        return hi;
    }
};