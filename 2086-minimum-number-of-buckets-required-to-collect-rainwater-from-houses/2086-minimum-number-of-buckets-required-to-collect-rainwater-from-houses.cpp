class Solution
{
    public:
    int minimumBuckets(string s)
    {
        int buckets = 0;        
        int N = s.size();       
        for (int i=0; i<N; i++)
        {
            if (s[i] == 'H')
            {
                if (i > 0 && s[i-1] == 'B')
                    continue;
            
                if (i+1<N && s[i+1] == '.')
                {
                    s[i+1] = 'B';
                    buckets++;
                }
                else if (i-1>=0 && s[i-1] == '.')               
                {
                    s[i-1] = 'B';
                    buckets++;
                }
                else
                    return -1;
            }            
        }        
        return buckets;
    }
};