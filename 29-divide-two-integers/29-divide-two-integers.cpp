class Solution
{
    public:
    int divide(int origDividend, int origDivisor)
    {
        if (origDividend == INT_MIN && origDivisor == -1)
            return INT_MAX;
        
        return floor(origDividend/origDivisor);
    }
};