class Solution
{
    public:
    int numTimesAllBlue(vector<int>& flips)
    {
        // 1         = 1
        // 1+2       = 3
        // 1+2+3     = 6
        
        int currSum = 0;
        int expectedSum = 0;
        int count = 0;
        for (int i=0; i<flips.size(); i++)
        {
            currSum += flips[i];
            expectedSum += (i+1);
            if (currSum == expectedSum)
                count++;
        }
        return count;
    }
};