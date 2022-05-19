/*
class Solution
{
    public:
    int numTimesAllBlue(vector<int>& flips)
    {
        // 1         = 1 <-- expected sum at i=0
        // 1+2       = 3 <-- expected sum at i=1
        // 1+2+3     = 6 <-- expected sum at i=2
        
        int currSum = 0;
        int expectedSum = 0;
        int res = 0;
        for (int i=0; i<flips.size(); i++)
        {
            currSum += flips[i];
            expectedSum += (i+1);
            if (currSum == expectedSum)
                res++;
        }
        return res;
    }
};
*/

class Solution
{
    public:
    int numTimesAllBlue(vector<int>& flips)
    {
        int res = 0, rightMost = -1;
        for (int i=0; i<flips.size(); i++)
        {
            // (i+1) ==> number of bulbs we turned on so far.
            
            if (flips[i] > rightMost)
                rightMost = flips[i];  // Keep track of the right most turned-on bulb.
            
            if (rightMost == i+1)      // If the count of bulbs (i+1) is same as the right most turned-on bulb, BINGO!
                res++;
        }
        return res;
    }
};