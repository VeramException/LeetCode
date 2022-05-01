class Solution
{
public:
    long long appealSum(string s)
    {
        long long res = 0;

        // count the contribution of each character to the final sum
        for (char c='a'; c<='z'; c++)
            res += appealSumUtil(c, s);

        return res;
    }

    long long appealSumUtil(char c, string& s)
    {
        long long N = s.size();
        long long allCombs = N * (N+1)/2;
          
        long long count = 0;
        long long currCombs = 0;

        // Find the count of combinations that won't have c in them
        for (int i=0; i<N; i++)
        {
            // Every time you get a c, calculate the number of combinations that are possible from previous 'count' characters.
            // Note that the formula for 'how many combinations can we form with n characters' = n * (n+1)/2
            if (s[i] == c)
            {
                currCombs += count*(count+1)/2;
                count = 0;
            }
            else
                count++;
        }
        
        // Count the combinations for the last sub-string too
        currCombs += count*(count+1)/2;
        
        // All combinations - (combinations that wont have c)
        return allCombs - currCombs;
    }
};

// Here is the faster DP solution - same as prefix sum
// https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996203/DP
