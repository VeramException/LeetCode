class Solution
{
    public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        if (nums.size() < 3)
            return 0;
        
        sort (nums.begin(), nums.end());
        
        int closest = nums[0] + nums[1] + nums[2];        
        for (int i=0; i<nums.size()-2; i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            
            // avoid duplicate comparisons
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            while (j < k)
            {
                int currSum = nums[i] + nums[j] + nums[k];
                
                if (currSum == target)
                    return currSum;
                
                if (abs(target-currSum) < abs(target-closest))
                    closest = currSum;
                
                if (currSum > target)
                    k--;
                else
                    j++;
            }
        }
        
        return closest;
    }
};