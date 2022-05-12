class Solution
{
    public:
    int minimumBuckets(string s)
    {
        int buckets = 0;        
        int N = s.size();       
        for (int i=0; i<N; i++)
        {
            if (i > 0 && s[i-1] == 'B' && s[i] == 'H')
                continue;
            else if (i < N-1 && s[i] == 'H' && s[i+1] == '.')
            {
                s[i+1] = 'B';
                buckets++;
            }
            else if (i > 0 && s[i-1] == '.' && s[i] == 'H')
            {
                s[i-1] = 'B';
                buckets++;
            }
            else if (s[i] == 'H')
                return -1;         
        }        
        return buckets;
    }
};