class Solution
{
    public:
    bool isStrobogrammatic(string num)
    {
        vector<int> m (10, -1);
        m[0] = 0;
        m[1] = 1;
        m[6] = 9;
        m[8] = 8;
        m[9] = 6;
        
        int N = num.size();
        for (int i=0, j=N-1; i<=j; i++,j--)
        {
            if (m[num[i]-'0'] != num[j]-'0')
                return false;
        }
        
        return true;
    }
};