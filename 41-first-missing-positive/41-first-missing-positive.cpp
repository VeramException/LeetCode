class Solution 
{
    public:
    
    int firstMissingPositive(vector<int>& nums) 
    {
        // nums  = [0,1,2,3,4,5,  0,0]
        // index = [0,1,2,3,4,5,  6,7]
        nums.push_back(0);
        nums.push_back(0);

        // Step-1: Mark all negative numbers as '0'
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = 0;
                continue;
            }
        }
        
        // Step-2: For non-INT_MIN values, mark their indices as INT_MIN
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
        for (int i=1; i<nums.size();i++)
        {
            if (nums[i] >= 0)
                return i;
        }
        
        // we may never reach here.
        return 1;
    }
};