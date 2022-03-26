class Solution
{    
public:
    int search(vector<int>& nums, int target)
    {
        auto iter = std::lower_bound (nums.begin(), nums.end(), target);
        
        return (iter != nums.end() && *iter == target)? (iter - nums.begin()): -1;
    }
};