class Solution
{
    public:
    int numTimesAllBlue(vector<int>& flips)
    {
        // 1         = 1
        // 1+2       = 3
        // 1+2+3     = 6
        
        int sum = 0;
        int count = 0;
        for (long long i=0; i<flips.size(); i++)
        {
            sum += flips[i];
            if (sum == ((i+1)*(i+2))/2)
                count++;
        }
        return count;
    }
};