class Solution
{
    public:
    vector<int> arrayRankTransform(vector<int>& nums)
    {
        map<int, vector<int>> m;
        for (int i=0; i<nums.size(); i++)
            m[nums[i]].push_back(i);
        
        int rank = 0;
        for (auto iter: m)
        {
            ++rank;
            for (int index: iter.second)
                nums[index] = rank;
        }
        
        return nums;
    }
};