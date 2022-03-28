class Solution
{
    public:
    bool search(vector<int>& nums, int target)
    {
        int N = nums.size();
        return searchUtil(nums, target, 0, N-1);
    }
    
    bool searchUtil(vector<int>& nums, int target, int start, int end)
    {
        if (start > end)
            return false;
        
        int mid = (start+end)/2;
        
        if (nums[mid] == target)
            return true;
        
        return searchUtil(nums, target, start, mid - 1) || searchUtil(nums, target, mid + 1, end);
    }
};