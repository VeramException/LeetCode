class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int numsSize = nums.size();
        vector<vector<int>> result;

        if (numsSize < 3)
            return result;

        // sort the array
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < numsSize-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int requiredTwoSum = 0 - nums[i];

            // Two pointer technique to find requiredTwoSum in a sorted array
            int left = i + 1;
            int right = numsSize - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] == requiredTwoSum)
                {
                    result.push_back({nums[i],nums[left],nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] > requiredTwoSum)
                {
                    right = right - 1;
                }
                else if (nums[left] + nums[right] < requiredTwoSum)
                {
                    left = left + 1;
                }
            }
        }

        return result;
    }
};