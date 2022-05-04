class Solution
{
    public:
    string longestPalindrome(string s)
    {
        vector<int> res = {0, 0}; // {l, r}
        
        int i = 0;
        int n = s.size();
        while (i < n)
        {
            // Odd size  ==>  a b c (d) c b a
            int l=i, r=i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (res[1]-res[0]+1 < r-l+1)
                {
                    res[0] = l;
                    res[1] = r; 
                }
                l--;
                r++;
            }
            
            
            // Even size ==>  a b (c) (c) b a
            l=i, r=i+1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (res[1]-res[0]+1 < r-l+1)
                {
                    res[0] = l;
                    res[1] = r; 
                }
                l--;
                r++;
            }            
            
            i++;
        }
        
        return s.substr(res[0], res[1]-res[0]+1);
    }
};