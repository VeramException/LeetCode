class Solution
{
    public:
    int firstMissingPositive(vector<int>& nums)
    {
        // Step-0: Push two more dummy values
        nums.push_back(0);
        nums.push_back(0);        
        
        // Step-1: Mark all -ve numbers as '0'.
        //         After this step, all numbers in the array are >= 0.
        for (int& num: nums)
            if (num < 0)
                num = 0;
        
        // *** Core Step ***
        // Step-2: 
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != INT_MIN && abs(nums[i]) < nums.size())
            {
                int index = abs(nums[i]);
                if (nums[index] == 0)
                {
                    nums[index] = INT_MIN;
                    continue;
                }
                nums[index] = -abs(nums[index]);
            }
        }
        
        // Step-3: The first 'index' which has a positive value is the answer.
        for(int i=1; i<nums.size(); i++)
            if (nums[i] >= 0)
                return i;
        
        return 0;
    }
};