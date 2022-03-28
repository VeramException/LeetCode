class Solution
{
    public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        
        while (left <= right)
        {
            int mid = (left + right) / 2;
            
            if (nums[mid] < target)
            {
                // If middle is on right part, we have: nums[left] > nums[right] >= nums[middle].
                // When middle is on right part and target is greater than nums[right] (means not in nums[middle .. right]),
                // should search in left part.
                if (nums[left] > nums[mid] && target > nums[right])
                    right = mid - 1;
                // When (1) middle is on left part, (2) middle is on right part and target is in nums[middle ... right],
                // continue search in right part.
                else 
                    left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                // If middle is on left part, we have: nums[middle] >= nums[left] > nums[right]
                // When middle is on left part and target is smaller than nums[left] (means not in nums[left .. middle]),
                // should search in right part.
                if (nums[mid] > nums[right] && target < nums[left])
                    left = mid + 1;
                // When (1) middle is on the right part, (2) middle is on left part and target is in nums[left .. middle],
                // continue search in left part.
                else 
                    right = mid - 1;
            }
            else //nums[mid] == target
                return mid;
        }
        
        return -1;
    }
};