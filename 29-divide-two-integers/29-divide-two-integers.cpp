class Solution
{
    public:
    int divide(int origDividend, int origDivisor)
    {
        if (origDividend == INT_MIN && origDivisor == -1)
            return INT_MAX;
        
        bool negativeResult = ((origDividend<0)^(origDivisor<0));
        
        long int quotient = 0;
        long int dividend = labs(origDividend);
        long int divisor  = labs(origDivisor);

        while (dividend-divisor > 0)
        {
            unsigned int x = -1;
            while (dividend-divisor > 0)
            {
                x++;                
                divisor = divisor<<1;
            }
            quotient += 1<<x;
            dividend = dividend-(divisor>>1);
            divisor  = labs(origDivisor);
        }
        
        if (dividend-divisor == 0)
            quotient++;
        
        return (negativeResult)? -quotient: quotient;
    }
};