class Solution
{
    public:
    bool validPalindrome(string s)
    {
        int l = 0;
        int r = s.size()-1;
        
        return isValidPalindromeUtil(s, l, r, 0);
    }
    
    bool isValidPalindromeUtil(string &s, int l, int r, int count)
    {
        if (count > 1)
            return false;
        
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
                return isValidPalindromeUtil(s, l+1, r, count+1) ||
                       isValidPalindromeUtil(s, l, r-1, count+1);
        }
        return true;
    }
};