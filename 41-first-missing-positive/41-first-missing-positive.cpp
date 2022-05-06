class Solution 
{
    public:
    
    int firstMissingPositive(vector<int>& nums) 
    {
        // nums  = [0,1,2,3,4,5,  0,0]
        // index = [0,1,2,3,4,5,  6,7]
        nums.push_back(0);
        nums.push_back(0);

        // Step-1: Mark all negative numbers as '0'. They are useless.
        for (int i=0; i<nums.size(); i++)
            if (nums[i] < 0)
                nums[i] = 0;
        
        // Step-2: If you see a value in the array, mark that index as -ve.
        //         In this way we can keep track of what values did we see.
        for(int i=0; i<nums.size(); i++)
        {
            int index = abs(nums[i]);
            
            if (index >= nums.size())
                continue;
            else if (nums[index] == 0)
                nums[index] = INT_MIN;
            else
                nums[index] = -abs(nums[index]);
        }
        
        // Step-3: The first 'index' which has a positive value is the answer.
        for (int i=1; i<nums.size();i++)
            if (nums[i] >= 0)
                return i;
        
        // we may never reach here.
        return 1;
    }
};