class Solution
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> nextGreater;
        
        // Basically, find the next greater element of all elements in nums2
        stack<int> s;
        for (int num: nums2)
        {
            while (s.size() > 0 && s.top() < num)
            {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> res;
        for (int num: nums1)
        {
            if (nextGreater.count(num) > 0)
                res.push_back(nextGreater[num]);
            else
                res.push_back(-1);
        }
        return res;
    }
};