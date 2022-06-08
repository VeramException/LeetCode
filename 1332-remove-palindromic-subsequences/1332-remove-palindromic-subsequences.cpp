class Solution
{
    public:
    int removePalindromeSub(string s)
    {
        return s.empty()? 0: (isPalindrome(s)? 1: 2);
    }
    
    bool isPalindrome(string& s)
    {
        int l = 0, r = s.size()-1;
        while (l <= r && s[l] == s[r])
            l++, r--;
        return l>r;
    }
};