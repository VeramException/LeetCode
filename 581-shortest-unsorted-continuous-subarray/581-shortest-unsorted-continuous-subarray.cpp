class Solution
{
    public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        
        bool foundUnsorted = false;
        
        // Loop-1: Go through the loop and find the MIN value, if there are any unsorted values
        // Left ------> Right
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] < nums[i-1]) 
                foundUnsorted = true;
            
            if (foundUnsorted) 
                minVal = min(minVal, nums[i]);
        }
        
        // Loop-2: Go through the loop and find the MAX value, if there are any unsorted values
        // Left <------ Right
        foundUnsorted = false;
        for (int i=nums.size()-2; i>=0; i--)
        {
            if (nums[i] > nums[i+1]) 
                foundUnsorted = true;
            
            if (foundUnsorted) 
                maxVal = max(maxVal, nums[i]);
        }
        
        // Imp: Please understand that the above min_val and max_val are found inside the unsorted territory
        //      while scanning left -> right and left <- right.
        //      Now just go through the loop and find the first value that is larger  than min_val, and
        //                                            the last  value that is smaller than max_val
        
        // Loop-3: Go through the loop and find where
        int l, r;
        for (l = 0; l < nums.size(); l++)
            if (nums[l] > minVal)
                break;
        
        for (r = nums.size()-1; r>=0; r--)
            if (nums[r] < maxVal)
                break;
        
        return (r-l < 0)? 0: r-l+1;
    }
};


/* *********** Sorting technique - O(n Log(n))
class Solution
{
    public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        
        int start = -1;
        int end   = -1;
    
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] != sortedNums[i])
            {
                if (start == -1)
                    start = i;
                else
                    end = i;
            }            
        }
        
        return (start == -1)? 0: end-start+1;
    }
};
*/