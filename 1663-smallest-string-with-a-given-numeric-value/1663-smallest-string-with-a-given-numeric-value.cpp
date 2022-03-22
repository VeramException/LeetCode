class Solution
{
    public:
    string getSmallestString(int n, int k)
    {
        string res = string(n, 'a');
        
        k = k - n;
        
        while (k > 0)
        {
            n--;
            res[n] = res[n] + min(25, k);
            k = k - min(25, k);
        }
        
        return res;
    }
};