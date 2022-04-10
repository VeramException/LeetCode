class Solution
{
    public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;  // value, index
        
        for (int i=0; i<nums.size(); i++)
        {
            int numToFind = target - nums[i];
            
            if (m.count(numToFind) > 0)
                return {i, m[numToFind]};

            m[nums[i]] = i;
        }
        
        return {};
    }
};