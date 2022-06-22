class Solution
{
    public:
    int findKthLargest(vector<int>& nums, int k)
    {
        multiset<int> ms;
        for (int num: nums)
        {
            ms.insert(num);
            if (ms.size() > k)
                ms.erase(ms.begin());
        }        
        return *ms.begin();
    }
};