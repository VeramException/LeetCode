class Solution
{
    public:
    int minFlipsMonoIncr(string s)
    {
        int leftOnes    = 0;
        int rightZeroes = 0;
        
        // First calculate all zeroes on the right.
        for (char c: s)
            if (c == '0')
                rightZeroes++;        
        
        // Then for each character from left, count ones and then calculate the best min.
        int minFlips = rightZeroes;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '1')
                leftOnes++;
            else
                rightZeroes--;
            
            minFlips = min(minFlips, leftOnes+rightZeroes);
        }
        return minFlips;
    }
};