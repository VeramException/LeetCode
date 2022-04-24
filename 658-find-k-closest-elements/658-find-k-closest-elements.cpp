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

// When solution is sorted, we can find lower bound and upper bound and just return array[lo, lo+k]
class Solution
{
    public:
    
    vector<int> findClosestElements(vector<int>& nums, int k, int x)
    {
         int lo = 0;
         int hi = nums.size()-1;
         
         while (hi-lo >= k)
         {
             if (abs(nums[lo] - x) > abs(nums[hi] - x))
                 lo++;
             else
                 hi--;
                 
         }
         return vector<int>(nums.begin() + lo, nums.begin() + lo + k);
    }
};

