class Solution
{
    public:
    int findDuplicate(vector<int>& nums)
    {
        // Phase-1: Find loop
        int slow = nums[0];
        int fast = nums[0];
        bool isCycleFound = false;
        
        while (!isCycleFound)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if (slow == fast)
                isCycleFound = true;
        }
        
        // Phase-2
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};