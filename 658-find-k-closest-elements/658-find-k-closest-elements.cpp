// The following solution is when the array is unsorted.
/*
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
*/

// When solution is sorted, we can find the first closest element by binary search
class Solution
{
    public:
    
    vector<int> findClosestElements(vector<int>& nums, int k, int x)
    {
         int lo = 0;
         int hi = nums.size()-k;
         
         while (lo < hi)
         {
             int mid = (lo + hi) / 2;
             
             if (x - nums[mid] > nums[mid + k] - x)
                 lo = mid + 1;
             else
                 hi = mid;
         }
         return vector<int>(nums.begin() + lo, nums.begin() + lo + k);
    }
};

