class Solution
{
    public:
    int getMaxLen(vector<int>& nums)
    {
        // For positive product.
        // (1) Need even number of -ve numbers
        // (2) No Zeroes.
        
        int firstNegative = -1;
        int zeroPosition  = -1;
        int negativeCount = 0;
        int maxLen        = 0;
            
        for (int i=0; i<nums.size(); i++) 
        {
            if (nums[i] < 0)
            {
                negativeCount++; 
                if (firstNegative == -1) firstNegative = i;
            }
            
            if (nums[i] == 0)
            {
                negativeCount = 0;
                firstNegative = -1;
                zeroPosition  = i;
            }
            else
            {
                if (negativeCount%2 == 0)
                    maxLen = max(maxLen, i-zeroPosition);
                else
                    maxLen = max(maxLen, i-firstNegative);
            }
        }
        
        return maxLen;
    }
};