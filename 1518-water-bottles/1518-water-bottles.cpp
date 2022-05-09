class Solution
{
    public:
    int numWaterBottles(int full, int k)
    {
        int drank = 0;
        int empty = 0;
        
        while (full > 0)
        {
            drank += full;
            empty += full;
            full = empty/k;
            empty = empty%k;
        }
        return drank;
    }
};
