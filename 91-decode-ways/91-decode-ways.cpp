class Solution
{
    public:
    int numDecodings(string digits)
    {
        if (digits.size() == 0 || digits[0] == '0')
            return 0;
        
        int n = digits.size();
        vector<int> count(n+1, 0);
        
        count[0] = 1;
        count[1] = 1;
        
        for (int i=2; i<=n; i++)
        {
            // (1) Single digit
            if (digits[i - 1] > '0')
                count[i] = count[i - 1];
            
            // (2) Double digit
            if (digits[i-2] == '1' ||
                (digits[i-2] == '2' && digits[i-1] <= '6'))
            {
                count[i] = count[i] + count[i-2];
            }
        }
        
        return count[n];
    }
};